# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2021 Victor Eijkhout
####
#### makefile for Catch2 unit testing
####
################################################################

PROGRAMS = require

LANGUAGE = CXX
INCLUDES = -I${TACC_CATCH2_INC}
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
include ../Make.inc
CPPSTANDARD = 17

RUNS =

RUNS += run_require
.PHONY: run_require
run_require : require
	@./require [1]

RUNS += run_requirerr
.PHONY: run_requirerr
run_requirerr : require
	@./require [2] \
	| awk '/FAILED/ {p=1} p==1 {print}'

RUNS += run_requireven
.PHONY: run_requireven
run_requireven : require
	@./require [3]

RUNS += run_requirgen
.PHONY: run_requirgen
run_requirgen : require
	@./require [4]

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
