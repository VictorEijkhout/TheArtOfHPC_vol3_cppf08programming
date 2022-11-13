# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++11 and Fortran2003
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018-2021 Victor Eijkhout
####
#### Examples of Fortran I/O constructs
####
################################################################

PROGRAMS = fio asterisk

RUNS = 

.PHONY: run_asterisk
RUNS += run_asterisk
run_asterisk : asterisk
	@./asterisk

LANGUAGE = F
include ../Make.inc

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
