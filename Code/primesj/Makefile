# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
################################################################

PROGRAMS = primetest primefunction primestruct primeiterate

LANGUAGE = J
include ../Make.inc

RUNS =

.PHONY: run_primetest
RUNS += run_primetest
run_primetest : 
	@for n in 8 9 13 15 ; do \
	    echo $$n | julia primetest.j \
	    ; \
	done

.PHONY: run_primefunction
RUNS += run_primefunction
run_primefunction : 
	@for n in 8 9 13 15 ; do \
	    echo $$n | julia primefunction.j \
	    ; \
	done
include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
