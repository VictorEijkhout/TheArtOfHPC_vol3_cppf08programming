# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-9 Victor Eijkhout
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
INCLUDES = -I${TACC_GSL_INC}
# ${HOME}/Installation/gsl/gsl-lite/include
# INCLUDES += -I/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks/Accelerate.framework/Versions/A/Frameworks/vecLib.framework/Versions/A/Headers
# EXTRALIBS=-framework Accelerate
else
INCLUDES = -I${TACC_GSL_INC}
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
