# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018-2021 Victor Eijkhout
####
#### skeletons for exercises
####
################################################################

PROGRAMS = ijloop stream newton pointclass

LANGUAGE = CXX
include ../code/Make.inc

RUNS =

RUNS += run_ijloop
run_ijloop : ijloop
	@./ijloop

RUNS += run_newton
run_newton : newton
	@./newton

RUNS += run_stream
run_stream : stream
	@./stream

info ::
	@echo "make sync : with student repo"
include ../makefiles/Make.repo
.PHONY:  sync
sync :
	src=`pwd` \
	 && cd "${STUDENTREPO}/skeletons" \
	 && rsync $$src/*.{cxx,sh} .

## clean rules come from Make.inc above

