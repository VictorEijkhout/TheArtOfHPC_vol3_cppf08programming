# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2021 Victor Eijkhout
####
#### makefile for ray tracing
####
################################################################

PROGRAMS = randomppm

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

RUNS =

RUNS += run_ppm
.PHONY: run_ppm
run_ppm : randomppm
	@./randomppm > randomppm.ppm
randomppm.o : imglib.h

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
total_clean ::
	@rm -f *.ppm
