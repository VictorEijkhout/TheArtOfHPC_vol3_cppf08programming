# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019-2022 Victor Eijkhout
####
#### random number examples
####
################################################################

PROGRAMS = crand xrand intrange shuffle permute static uniform \
    walk_vec walk_arr walk_pass walk_test

LANGUAGE = CXX
INCLUDES = -I${TACC_CATCH2_INC} -I${HOME}/Installation/cxxopts/installation/include
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
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
.PHONY: run_vec run_arr run_pass
walk_vec.o walk_test.o : walk_lib_vec.cxx
walk_arr.o : walk_lib_arr.cxx
walk_pass.o : walk_lib_pass.cxx
run_vec : walk_vec
	@./walk_vec
run_arr : walk_arr
	@./walk_arr
run_pass : walk_pass
	@./walk_pass

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
