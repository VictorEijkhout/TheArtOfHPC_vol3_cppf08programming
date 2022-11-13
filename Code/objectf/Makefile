# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017 Victor Eijkhout
####
#### Examples of F90 OOP
####
################################################################

PROGRAMS = mult1 final
WRONGS = mult2

LANGUAGE = F
include ../Make.inc

RUNS =

RUNS += run_mult1
.PHONY: run_mult1
run_mult1 : mult1
	@./mult1

RUNS += run_final
.PHONY: run_final
run_final : final
	@./final
include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
