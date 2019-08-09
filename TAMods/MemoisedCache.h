#pragma once

#include <string>
#include <functional>
#include <map>

template <typename K, typename V>
class MemoisedCache {
private:
	std::map<K, V> cache;
	std::function<V(K)> insertTransformer;
public:
	MemoisedCache(std::function<V(K)> transformer) : cache(), insertTransformer(transformer) {}

	V &operator[](K key) {
		if (cache.find(key) == cache.end()) {
			cache[key] = insertTransformer(key);
		}
		return cache[key];
	}
};

// This cache is an attempt to fix crashing on exit
// I believe the crash is due to Unreal GC attempting to clean up strings which are actually constants
// So instead, I am making sure they are all allocated on the heap, stored in this cache
extern MemoisedCache<std::string, wchar_t*> fStringCache;
