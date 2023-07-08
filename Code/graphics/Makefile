# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
####
#### makefile for sfml graphics
####
################################################################

PROGRAMS = basic
WRONGS   = 

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

## NOTE: on MacOS sfml can only be compiled with clang

MODULES = sfml
INCLUDES  = -I${TACC_SFML_INC}
EXTRALIBS = -L${TACC_SFML_LIB} -lsfml-graphics -lsfml-window -lsfml-system
RPATH = ${TACC_SFML_LIB}

RUNS =

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
