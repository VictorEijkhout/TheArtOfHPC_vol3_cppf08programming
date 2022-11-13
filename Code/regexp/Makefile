# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019 Victor Eijkhout
####
#### regular expression examples
####
################################################################

PROGRAMS = regexp regsearch

LANGUAGE = CXX
include ../Make.inc

RUNS =

.PHONY: run_regexp
RUNS += run_regexp
run_regexp : regexp
	@./regexp

.PHONY: run_search
RUNS += run_search
run_search : regsearch
	@./regsearch



include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
