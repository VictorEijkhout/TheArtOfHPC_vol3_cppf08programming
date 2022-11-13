#
# compile script for the bisection exercise
#
# note the number in the source name:
# valid drivers are 1,2,3,4,5 for the individual tests
# and 0 for all tests.
#
# all source files have a line:
#  #include "YOUR FILE HERE"
# which you can change to the name of your own file.
# 
clang++ -std=c++17 -g  -o bisection_driver bisection_driver1.cxx -I${TACC_CATCH2_INC} -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
