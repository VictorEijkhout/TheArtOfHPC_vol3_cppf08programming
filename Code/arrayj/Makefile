# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2020 Victor Eijkhout
####
#### Makefile for Julia code directory "array"
####
################################################################

PROGRAMS = bounds push pointwise

LANGUAGE = J
include ../Make.inc

RUNS =

.PHONY: run_bounds
RUNS += run_bounds
run_bounds : 
	@julia bounds.j

.PHONY: run_pointwise
RUNS += run_pointwise
run_pointwise : 
	@julia pointwise.j

.PHONY: run_push
RUNS += run_push
run_push : 
	@julia push.j

include ../../makefiles/Make.clean
