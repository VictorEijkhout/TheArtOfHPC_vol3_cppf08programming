# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018 Victor Eijkhout
####
#### F90 analysis of climate record
####
################################################################

PROGRAMS = annual

include ../Make.inc
LINKER = gfortran

RUNS =

RUNS += run_annual
.PHONY: run_annual
info ::
	@echo "    [ DATAFILE=.... (default: ${DATAFILE}) ]"
##codesnippet runannual
DATAFILE = GLB.Ts.txt
run_annual : annual
	@(    cat ${DATAFILE} | grep '^[12]' | grep -v 2018 | wc -l \
	   && cat ${DATAFILE} | grep '^[12]' | grep -v 2018 \
	 ) | ./annual
##codesnippet end

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
