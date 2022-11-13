# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018 Victor Eijkhout
####
#### makefile for Erathostenes sieve
####
################################################################

PROGRAMS = ints odds primes complexity scratch

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 14

RUNS =

RUNS += run_ints
.PHONY: run_ints
run_ints : ints
	@./ints

RUNS += run_odds
.PHONY: run_odds
run_odds : odds
	@./odds

RUNS += run_scratch
.PHONY: run_scratch
run_scratch : scratch
	@echo 100 | ./scratch

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
