# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++11 and Fortran2003
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
####
#### Number theory project
####
#### https://ridiculousfish.com/blog/posts/labor-of-division-episode-iv.hpptml
#### https://janmr.com/blog/2014/04/basic-multiple-precision-long-division/
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
inttest.o : intlib.hpp
inttest : intlib.o

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
