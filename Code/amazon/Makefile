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

PROGRAMS = route

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

RUNS =

.PHONY: run_address
RUNS += run_address
run_address : route
	@./route \
| awk '/addresstest/ {p=0} p==1 {print} /Addresstest/ {p=1}'

.PHONY: run_route 
RUNS += run_route 
run_route : route
	@./route
.PHONY: run_square5
RUNS += run_square5
run_square5 : route
	@./route \
	2>&1 | awk '/square5/ {p=0} p==1 {print} /Square5/ {p=1}'
.PHONY: run_twoday
RUNS += run_twoday
run_twoday : route
	@./route \
	2>&1 | awk '/twoday/ {p=0} p==1 {print} /Twoday/ {p=1}'

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
