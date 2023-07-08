# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019-2023 Victor Eijkhout
####
#### random number examples
####
################################################################

PROGRAMS = crand xrand intrange shuffle permute static uniform \
    randname \
    walk_vec walk_arr walk_pass
WRONGS = walk_test

LANGUAGE = CXX
INCLUDES = -I${TACC_CATCH2_INC} -I${TACC_CXXOPTS_INC}
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
MODULES = catch2
include ../Make.inc

RUNS =

.PHONY: run_nonrandom
RUNS += run_nonrandom
run_nonrandom : static
	@./static \
	| awk '/nonrandom/ {p=0} p==1 {print} /Nonrandom/ {p=1}'
.PHONY: run_truerandom
RUNS += run_truerandom
run_truerandom : static
	@./static \
	| awk '/truerandom/ {p=0} p==1 {print} /Truerandom/ {p=1}'

RUNS += run_vec run_arr run_pass
walk_vec.o walk_test.o : walk_lib_vec.cpp
walk_arr.o : walk_lib_arr.cpp
walk_pass.o : walk_lib_pass.cpp
run_vec : walk_vec
	@./walk_vec
run_arr : walk_arr
	@./walk_arr
run_pass : walk_pass
	@./walk_pass

RUNS += run_shuffle
run_shuffle : shuffle
	@./shuffle

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
