#include "Profiler.h"

static std::map<std::string, Profiler::Function> functions;
static Profiler::Function *curr_function = NULL;
static unsigned long total_time = 0;
static unsigned long profiling_start = 0;
static bool active = false;

void Profiler::Function::enter()
{
	_start_time = timeGetTime();
}

unsigned long Profiler::Function::leave()
{
	unsigned long delta = timeGetTime() - _start_time;
	_tottime += delta;
	++_ncalls;
	return delta;
}

void Profiler::Function::computeTimes()
{
	_percall = _tottime / _ncalls;
	_percentage = (100.0f * _tottime) / (float)total_time;
}

void Profiler::enterFunction(const std::string &fname)
{
	if (!active)
		return;
	curr_function = &functions[fname];
	if (curr_function->getName() == "")
		curr_function->setName(fname);
	curr_function->enter();
}

void Profiler::leaveFunction()
{
	if (!active)
		return;
	if (curr_function)
		total_time += curr_function->leave();
}

void Profiler::start()
{
	functions.clear();
	curr_function = NULL;
	total_time = 0;
	profiling_start = timeGetTime();
	active = true;
	Utils::notify(L"TAMods", "Profiler started");
}

void Profiler::stop()
{
	// Deactivate the profiler
	active = false;

	// Sort and compute results
	std::vector<Profiler::Function*> sorted_funcs;
	int total_calls = 0;
	for (auto &it : functions)
	{
		it.second.computeTimes();
		total_calls += it.second.getNCalls();
		sorted_funcs.push_back(&it.second);
	}
	std::sort(sorted_funcs.begin(), sorted_funcs.end(), [](Function *a, Function *b) -> bool { return a->getPercentage() < b->getPercentage(); });

	// Log results
	Logger::log("Profiler results: %d calls (%d uniques) registered in %.3f sec", total_calls, sorted_funcs.size(), (float)(timeGetTime() - profiling_start) / 1000.0f);
	Logger::log("%-10s %-10s %-10s %-10s %s", "ncalls", "tottime", "percall", "percentage", "funcname");
	for (auto it : sorted_funcs)
		Logger::log("%-10d %-10.3f %-10.3f %-10.3f %s", it->getNCalls(), (float)it->getTotalTime() / 1000.0f, (float)it->getTimePerCall() / 1000.0f, it->getPercentage(), it->getName().c_str());
	Utils::notify(L"TAMods", "Profiler stopped");
}

void Profiler::toggle()
{
	if (active)
		stop();
	else
		start();
}

bool Profiler::isActive()
{
	return active;
}
