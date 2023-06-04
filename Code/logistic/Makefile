# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019 Victor Eijkhout
####
#### makefile for truck routing
####
################################################################

PROGRAMS = iterate

LANGUAGE = CXX
include ../Make.inc

RUNS =

.PHONY: run_iterate 
RUNS += run_iterate 
run_iterate : iterate
	@echo .5 | ./iterate

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
