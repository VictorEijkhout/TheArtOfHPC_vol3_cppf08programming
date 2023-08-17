# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019-2023 Victor Eijkhout
####
#### C++20 span & C++23 mdspan tests
####
################################################################

PROGRAMS = transpose 

LANGUAGE = CXX
MODULES = mdspan rangev3
INCLUDES = -I${TACC_MDSPAN_INC} -I${TACC_RANGEV3_INC}
CPPSTANDARD = 23
include ../Make.inc

RUNS =

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
