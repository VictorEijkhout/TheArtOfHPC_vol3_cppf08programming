# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019-2022 Victor Eijkhout
####
#### gdb examples
####
################################################################

PROGRAMS = hello root assert overflow bound

include ../Make.inc
LANGUAGE = CXX
OPTLEVEL = 0

RUNS =
RUNS += run_overflow
run_overflow : overflow
	@./overflow | head -n 20
.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
