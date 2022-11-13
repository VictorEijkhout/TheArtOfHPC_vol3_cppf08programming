# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017/8 Victor Eijkhout
####
#### Examples of C++ casting
####
################################################################

PROGRAMS = longint intlong tobase toderived

.PHONY: run_longint
RUNS += longint
run_longint : longint
	@./longint

.PHONY: run_intlong
RUNS += intlong
run_intlong : intlong
	@./intlong

.PHONY: run_toderived
RUNS += toderived
run_toderived : toderived
	@./toderived

.PHONY: deriveright derivewrong run_deriveright run_derivewrong
deriveright : 
RUNS += deriveright
run_deriveright : toderived
	@./toderived \
	| awk '/polymain/ {p=0} p==1 {print} /Polymain/ {p=1}'
derivewrong : 
RUNS += derivewrong
run_derivewrong : toderived
	@./toderived \
	| awk '/polybane/ {p=0} p==1 {print} /Polybane/ {p=1}'

LANGUAGE = CXX
include ../Make.inc

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
