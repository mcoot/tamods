# This script generates .cpp files from the sdk headers .h files
# It does NOT comment the lines 'UClass* ...::pClassPointer = NULL;' in the .h lines

to_rep="# .*"

include='#include "../SdkHeaders.h"

/*
# ========================================================================================= #
# Global Static Class Pointers
# ========================================================================================= #
*/

'

end=' '

# Create SDK_SOURCES directory
mkdir -p SDK_SOURCES
for fname in $(ls SDK_HEADERS | grep functions); do
    base=$(echo $fname | cut -d_ -f1);
    # Move & rename *_functions to .cpp
    cp -v "SDK_HEADERS/"$fname "SDK_SOURCES/"$base"_functions.cpp"
    # Move Global Static Class Pointers
    # Add #include "../SdkHeaders.h" at the beginning of the files
    decl=$(cat "SDK_HEADERS/"$base"_classes.h" | grep -Eo 'UClass\* [a-zA-Z0-9_]+::pClassPointer = NULL;');
    rep=$(echo -e "$include""$decl""\n" | sed -e 's/$/\\/g' | head -n -1)
    rep="$rep""$end"
    sed -i "16a \\$rep" "SDK_SOURCES/"$base"_functions.cpp"
done
