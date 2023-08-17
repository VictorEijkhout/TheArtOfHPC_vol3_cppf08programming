# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2023 Victor Eijkhout
####
#### makefile for descent methods
####
################################################################

PROGRAMS = 
WRONG = 

LANGUAGE = CXX
MODULES = catch2 cxxopts fmtlib
INCLUDES = \
    -I${TACC_CATCH2_INC} \
    -I${TACC_CXXOPTS_INC} \
    -I${TACC_FMTLIB_INC}
EXTRALIBS = \
    -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2 -lffi \
    -L${TACC_CXXOPTS_LIB} \
    -L${TACC_FMTLIB_LIB} -lfmt
RPATH = ${TACC_CATCH2_LIB} ${TACC_CXXOPTS_LIB} ${TACC_FMTLIB_LIB}

RUNS = 

PROGRAMS += ellipse
ellipse : minimlib.o vectorlib.o
minimlib.o ellipse.o : minimlib.h
vectorlib.o ellipse.o : vectorlib.h
RUNS += run_ellipse
run_ellipse : ellipse
	@./ellipse

.PHONY: ${RUNS}

include ../Make.inc

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
