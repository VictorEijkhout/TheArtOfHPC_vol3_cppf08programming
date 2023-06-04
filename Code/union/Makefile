# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2023 Victor Eijkhout
####
#### Makefile for union-like stuff: optional, variant
####
################################################################

PROGRAMS = intdoublestring visit quadratic quadtest \
    optional optroot
WRONG =  poly

INCLUDES = -I${TACC_CATCH2_INC}
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
include ../Make.inc
CPPSTANDARD = 17
LANGUAGE = CXX
MODULES = catch2

RUNS = 

RUNS += run_intdoublestring
run_intdoublestring : intdoublestring
	@./intdoublestring

RUNS += run_visit
run_visit : visit
	@./visit

RUNS += run_quadratic
run_quadratic : quadratic
	@./quadratic
quadratic.o :: quadlib.h

RUNS += run_quadtest
run_quadtest : quadtest
	@./quadtest
quadtest.o :: quadlib.h

RUNS += run_optional
run_optional : optional
	@./optional \
	| awk '/badvalue/ {p=0} p==1 {print} /BadValue/ {p=1}'

RUNS += run_optroot
run_optroot : optroot
	@./optroot

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
