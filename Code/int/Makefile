# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017 Victor Eijkhout
####
#### integer computations
####
################################################################

PROGRAMS = divzero unsigned

LANGUAGE = CXX
include ../Make.inc

.PHONY: run_div
RUNS += run_div
run_div : divzero
	@echo 0 | ./divzero

.PHONY: run_cmp
RUNS += run_cmp
run_cmp : unsigned
	@./unsigned \
	| awk '/cmp/ {p=0} p==1 {print} /Cmp/ {p=1}'

.PHONY: run_limit
RUNS += run_limit
run_limit : unsigned
	@./unsigned \
	| awk '/limit/ {p=0} p==1 {print} /Limit/ {p=1}'

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
