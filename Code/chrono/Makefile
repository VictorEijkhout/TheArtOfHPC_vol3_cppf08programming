# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019-2023 Victor Eijkhout
####
#### time stuff
####
################################################################

PROGRAMS = second clock
# C++20 not fully implemented
WRONGS = datetime

LANGUAGE = CXX
MODULES = fmtlib
INCLUDES = -I${LMOD_FMTLIB_INC}
EXTRA_LIBS = -L${LMOD_FMTLIB_LIB} -lfmt
include ../Make.inc
CPPSTANDARD = 20

RUNS =

RUNS += run_basicsecond run_millisecond
.PHONY: run_basicsecond run_millisecond
run_basicsecond run_millisecond : second
run_basicsecond :
	@./second | \
	awk '/basicseconds/ {p=0} p==1 {print} /BasicSeconds/ {p=1}'
run_millisecond :
	@./second | \
	awk '/milliseconds/ {p=0} p==1 {print} /MilliSeconds/ {p=1}'

RUNS += run_clock
.PHONY: run_clock
run_clock : clock
run_clock :
	@./clock

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
