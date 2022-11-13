# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018 Victor Eijkhout
####
#### makefile for dna sequencing examples and exercises
####
################################################################

PROGRAMS = bases virus quality match boyer

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

RUNS = 

.PHONY: run_bases
run_bases : bases
	@./bases

.PHONY: run_boyer
run_boyer : boyer
	@./boyer

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
