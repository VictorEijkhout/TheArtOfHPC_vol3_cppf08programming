# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++11 and Fortran2003
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
#### C++ modules
####
################################################################

PROGRAMS = fgmain helpermain
WRONGS = 

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 20
OPTIONS = -fmodules-ts

# link in the module
fgmain : fgmod.o
# make sure the module is compiled first
fgmain.o : fgmod.o

# main depends on module
helpermain : helpermod.o helperhelp.o
helpermain.o : helpermod.o
# module depends on helper
helpermod.o : helperhelp.o

RUNS = 

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
