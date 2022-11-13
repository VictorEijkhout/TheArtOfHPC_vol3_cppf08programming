# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018-2020 Victor Eijkhout
####
#### Exercises from The Book
####
################################################################

PROGRAMS = babylroot

LANGUAGE = CXX
include ../Make.inc

RUNS =

RUNS += run_babylroot
.PHONY: run_babylroot
run_babylroot : babylroot
run_babylroot :
	@for tol in .01 .001 .000001 .00000000001 ; do \
	  echo "================ tolerance: $$tol ================" \
	  && for number in 3 300 30000 3000000 ; do \
	       ( echo $$number && echo $$tol ) | ./babylroot \
	       && echo \
	       ; done \
	  ; done

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
