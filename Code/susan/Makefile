# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
################################################################

PROGRAMS = main test

LANGUAGE = CXX
INCLUDES = -I${TACC_CATCH2_INC}
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
MODULES = catch2
include ../Make.inc

RUNS = 

.PHONY: run_main
RUNS += run_main
run_main : main
	@./main
.PHONY: run_test
RUNS += run_test
run_test : test
	@./test
main.o test.o : functions.h

include ../../makefiles/Make.clean
