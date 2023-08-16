# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2023 Victor Eijkhout
####
################################################################

PROGRAMS = except1 except2 exceptroot exceptfp \
    exceptconstruct boundthrow catchbounds \
    tdd
WRONGS = location

LANGUAGE = CXX
MODULES = catch2
INCLUDES = -I${TACC_CATCH2_INC}
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
RPATH = ${TACC_CATCH2_LIB}

include ../Make.inc

RUNS =

.PHONY: run_boundthrow
RUNS += run_boundthrow
run_boundthrow : boundthrow
	@./boundthrow 2>&1 | grep -v make

.PHONY: run_catchbounds
RUNS += run_catchbounds
run_catchbounds : catchbounds
	@./catchbounds

.PHONY: run_tdd
run_tdd : tdd
	@./tdd

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
