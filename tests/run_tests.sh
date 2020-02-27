#! /bin/bash

# compile
make 2>&1 > /dev/null

# cunit test
source ./cunit.sh
cunit test

# memory leak test
source ./memory_leaks.sh
memory_leaks test

# clean
make clean 2>&1 > /dev/null

exit 0