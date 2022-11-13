# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019 Victor Eijkhout
####
#### makefile for queueing example
####
################################################################

PROGRAMS = queue

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

RUNS =

.PHONY: run_queue
RUNS += run_queue
run_queue : queue
	@./queue 10 20

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
