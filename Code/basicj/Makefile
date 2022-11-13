# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-9 Victor Eijkhout
####
#### Exploring basic Julia
####
################################################################

PROGRAMS =  scalar

LANGUAGE = J
include ../Make.inc
LINKER = julia

RUNS =

RUNS +=
.PHONY: run_d0
run_d0 : d0
	@( echo ${VALUE} ; echo ${VALUE} ) | ./d0 \
	    | awk '/thereandback/ {p=0} p==1 {print} /ThereAndBack/ {p=1}'

RUNS += run_scalar
run_scalar :
	@julia scalar.j
include ../../makefiles/Make.clean
