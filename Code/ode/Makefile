# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
####
#### copyright 2020-2022 Victor Eijkhout
####
#### ODE solving exercises
####
################################################################

PROGRAMS = pureint ballistics

LANGUAGE = CXX
include ../Make.inc

RUNS =

RUNS += run_pureint
.PHONY: run_pureint
run_pureint : pureint
	@./pureint
include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
