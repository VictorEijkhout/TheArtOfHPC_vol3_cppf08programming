# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2020 Victor Eijkhout
####
################################################################

PROGRAMS = point 

LANGUAGE = J
include ../Make.inc

.PHONY: ${RUNS}

RUNS += run_point
.PHONY: run_point
run_point : point
	./point
include ../../makefiles/Make.clean
