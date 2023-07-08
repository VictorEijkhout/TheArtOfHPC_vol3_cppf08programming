# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2023 Victor Eijkhout
####
################################################################

PROGRAMS = queens queentest
WRONG = 

LANGUAGE = CXX
INCLUDES  = -I${TACC_CATCH2_INC}
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
MODULES = catch2
include ../Make.inc

queens.o queentest.o : queens.hpp

RUNS = 

RUNS += run_queens
run_queens : queens
	@./queens

RUNS += run_test
run_test : queentest
	@for i in `seq 1 10` ; do \
	    echo "Unit test: $$i" \
	     && ./queentest [$$i] \
	    ; done

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
