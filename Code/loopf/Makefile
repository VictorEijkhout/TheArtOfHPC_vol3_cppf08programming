# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017 Victor Eijkhout
####
#### Examples of F90 looping
####
################################################################

PROGRAMS = labeled loopinf loops cycle
WRONGS = loopr

include ../Make.inc
LANGUAGE = F

RUNS =

# RUNS += run_plusone
# .PHONY: run_plusone
# run_plusone : plusone
# 	@./plusone

RUNS += run_loopr
.PHONY: run_loopr
run_loopr : loopr
	@./loopr

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
