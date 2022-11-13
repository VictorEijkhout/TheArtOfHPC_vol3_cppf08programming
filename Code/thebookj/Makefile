# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018-2020 Victor Eijkhout
####
#### Exercises from The Book, in Julia
####
################################################################

PROGRAMS = babylroot quadratic sieve

LANGUAGE = J
include ../Make.inc

RUNS =

RUNS += run_babylonian
.PHONY: run_babylonian
run_babylonian :
	@julia babylonian.j

RUNS += run_quadratic
.PHONY: run_quadratic
run_quadratic :
	@julia quadratic.j

RUNS += run_lambda
.PHONY: run_lambda
run_lambda :
	@julia lambda.j

include ../../makefiles/Make.clean
