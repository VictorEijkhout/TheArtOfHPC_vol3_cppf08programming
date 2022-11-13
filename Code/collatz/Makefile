# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-9 Victor Eijkhout
####
################################################################

PROGRAMS = 3np1 collatz collatzfun collatzstat \
    modular

LANGUAGE = CXX
include ../Make.inc

RUNS =

RUNS += run_3np1
.PHONY: run_3np1
run_3np1 : 3np1
	for i in 1 10 -2 17 ; do \
	  echo $$i | ./3np1 ; \
	done

RUNS += run_collatz
.PHONY: run_collatz
run_collatz : collatz
	@./collatz

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
