# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++11 and Fortran2003
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
####
#### Number theory project
####
################################################################

PROGRAMS = inttest

LANGUAGE = CXX
INCLUDES = -I${TACC_CATCH2_INC}
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
MODULES = catch2
include ../Make.inc
CPPSTANDARD = 17

RUNS += run_test
.PHONY: run_test
run_test : inttest
	@./inttest
inttest.o : intlib.h
inttest : intlib.o

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
