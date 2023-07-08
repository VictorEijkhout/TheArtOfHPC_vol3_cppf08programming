# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
#### makefile for number theory stuff in C++
####
################################################################

PROGRAMS = fraction_test
WRONG = 

LANGUAGE = CXX
INCLUDES = -I${TACC_CATCH2_INC}
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
MODULES = catch2
include ../Make.inc

RUNS = 

.PHONY: run_fractions
RUNS += run_fractions
run_fractions : fractions
	@./fractions
.PHONY: run_test
RUNS += run_test
run_test : fraction_test
	@./fraction_test
fractions.o fraction_test.o : fractionlib.hpp

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
