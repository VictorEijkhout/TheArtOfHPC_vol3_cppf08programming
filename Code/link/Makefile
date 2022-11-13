# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-9 Victor Eijkhout
####
#### makefile for linking examples
####
################################################################

PROGRAMS = static static17

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

RUNS = 

.PHONY: run_static
RUNS += run_static
run_static : static
	@./static

.PHONY: run_static17
RUNS += run_static17
run_static17 : static17
	@./static17

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
