# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019-2023 Victor Eijkhout
####
#### makefile for traffic simulation
####
################################################################

PROGRAMS = street

LANGUAGE = CXX
MODULES = catch2 fmtlib
INCLUDES = \
    -I${TACC_CATCH2_INC} \
    -I${TACC_FMTLIB_INC}
EXTRALIBS = \
    -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2 -lffi \
    -L${TACC_FMTLIB_LIB} -lfmt
ifeq "${TACC_FAMILY_COMPILER}" "gcc"
  OPTIONS = -Wno-psabi
endif
include ../Make.inc
CPPSTANDARD = 20

street : traffic_lib.o
CMAKE_EXTRA_SOURCES = traffic_lib.cxx
street.o traffic_lib.o : traffic_lib.hpp

RUNS =

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
