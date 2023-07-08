# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### copyright 2020-2023 Victor Eijkhout (eijkhout@tacc.utexas.edu)
####
#### Makefile for BLAS stuff
####
################################################################

PROGRAMS = lapack_alloc
WRONGS = lapack

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

ifeq "${TACC_SYSTEM}" "macbookair"
#OPTIONS=-DDEBUG
#OPTIONS=-DCBLAS
OPTIONS=
INCLUDES = -I${TACC_MSGSL_INC}
MODULES = gsl
else
INCLUDES = -I${TACC_MSGSL_INC}
endif

RUNS =

## RUNS += run_lapack
.PHONY: run_lapack
run_lapack : lapack
	@./lapack

RUNS += run_alloc
.PHONY: run_alloc
run_alloc : lapack_alloc
	@./lapack_alloc

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
