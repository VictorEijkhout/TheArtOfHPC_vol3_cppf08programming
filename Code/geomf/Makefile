# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
#### makefile for geometry exercises in Fortran
####
################################################################

PROGRAMS = point pointmain pointexample scalar field 
NOTYET = pointstruct pointconstruct pointinit pointprivate \
    pointfunc pointscale pointscaleby pointdefault \
    linear rectangle rectangle2 square

LANGUAGE = F
include ../Make.inc

pointmain.o : pointmod.mod
pointmain : pointmod.o

RUNS =

RUNS += point_run
.PHONY: point_run
point_run : point
	@./point > run.out && \
	cat run.out | awk '/1\.41/ { v = v+1 } /5\.0/ { v = v+1 } END {print v}' > chk.out && \
	n=` cat chk.out | awk '{print $$1}'` && \
	if [ $$n -ne 2 ] ; then \
	  echo "ERROR\n  Program point failed: output=" ; \
	  cat run.out ; \
	else \
	  echo "Program point ran successfully" ; \
	fi

RUNS += run_scalar
run_scalar : scalar
	@./scalar

RUNS += run_field
run_field : field
	@./field

RUNS += run_pointexample
run_pointexample : pointexample
	@./pointexample

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
