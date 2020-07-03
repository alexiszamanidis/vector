#! /bin/bash

# compile
cd ../source && make 2>&1 > /dev/null

# cunit test
cd ../scripts && source ./cunit.sh
cunit ../source/main

# memory leak test
source ./memory_leaks.sh
memory_leaks ../source/main

# clean
cd ../source && make clean 2>&1 > /dev/null

exit 0