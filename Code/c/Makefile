# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
################################################################

PROGRAMS = carray ctypes
WRONGS = pswap

LANGUAGE = C
include ../Make.inc
CSTANDARD = 11

RUNS = 

RUNS += run_carray
.PHONY: run_carray
run_carray :
	@make clean || rm -f carray
	@make --no-print-directory carray CSTANDARD=99 ECHO=1 2>/dev/null \
	 && ./carray
	@make clean || rm -f carray
	@make --no-print-directory carray CSTANDARD=11 ECHO=1 2>/dev/null \
	 && ./carray
RUNS += run_carraystat
.PHONY: run_carraystat
run_carraystat : carray
	@./carray \
	| awk '/statprint/ {p=0} p==1 {print} /Statprint/ {p=1}'

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
