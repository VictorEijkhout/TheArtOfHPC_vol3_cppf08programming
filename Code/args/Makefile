# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2021 Victor Eijkhout
####
#### makefile for commandline arg parsing
####
################################################################

PROGRAMS = argcv cxxopts

LANGUAGE = CXX
INCLUDES = -I${TACC_CXXOPTS_INC}
EXTRALIBS = 
include ../Make.inc
CPPSTANDARD = 17

RUNS =

RUNS += run_argcv
run_argcv : argcv
	./argcv 5 12
	./argcv abc 3.14 foo

RUNS += run_cxxopts
run_cxxopts : cxxopts
	./cxxopts -h
	./cxxopts -n 5 foo

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
