# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
####
################################################################

PROGRAMS = denorm nan round underflow

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

##
## regression runs
##
RUNS =

.PHONY: run_underflow
RUNS += run_underflow
run_underflow : underflow
	@./underflow

.PHONY: run_denorm
RUNS += run_denorm
run_denorm : denorm
	@./denorm

.PHONY: run_nan
RUNS += run_nan
run_nan : nan
	@./nan

.PHONY: run_round
RUNS += run_round
run_round : round
	@( echo .7 && echo .7 ) | ./round

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
