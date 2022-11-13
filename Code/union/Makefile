# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
#### Makefile for union-like stuff: optional, variant
####
################################################################

PROGRAMS = intdoublestring visit quadratic quadtest
WRONG =  poly

INCLUDES = -I${TACC_CATCH2_INC}
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
include ../Make.inc
LANGUAGE = CXX

RUNS = 

.PHONY: run_intdoublestring
RUNS += run_intdoublestring
run_intdoublestring : intdoublestring
	@./intdoublestring

.PHONY: run_visit
RUNS += run_visit
run_visit : visit
	@./visit

.PHONY: run_quadratic
RUNS += run_quadratic
run_quadratic : quadratic
	@./quadratic
quadratic.o :: quadlib.h

.PHONY: run_quadtest
RUNS += run_quadtest
run_quadtest : quadtest
	@./quadtest
quadtest.o :: quadlib.h

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
