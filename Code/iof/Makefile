# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2020 Victor Eijkhout
####
#### Examples of F90 I/O 
####
################################################################

PROGRAMS = hundred \
    adjust format

include ../Make.inc
LINKER = gfortran

RUNS =

RUNS += run_i4 run_ii run_ij
.PHONY: run_i4 run_ii run_ij
run_i4 : format
	@format \
	| awk '/i4/ {p=0} p==1 {print} /I4/ {p=1}'
run_ii : format
	@format \
	| awk '/ii/ {p=0} p==1 {print} /II/ {p=1}'
run_ij : format
	@format \
	| awk '/ij/ {p=0} p==1 {print} /IJ/ {p=1}'

RUNS += run_adjust
.PHONY: run_adjust
run_adjust : adjust
	@./adjust

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
