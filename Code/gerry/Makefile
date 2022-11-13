# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017/8 Victor Eijkhout
####
#### makefile for redistring examples
####
################################################################

PROGRAMS = count linear dynamic
WRONGS   = cutoff

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 14

RUNS =

.PHONY: run_linear
RUNS += run_linear
run_linear : linear
	@( echo 10 ; echo 5 ) | ./linear

.PHONY: run_voters
RUNS += run_voters
run_voters : linear
	@./linear \
	| awk '/voters/ {p=0} p==1 {print} /Voters/ {p=1}'

.PHONY: run_population
RUNS += run_population
run_population : linear
	@./linear \
	| awk '/populationbasics/ {p=0} p==1 {print} /Populationbasics/ {p=1}'

.PHONY: run_district
RUNS += run_district
run_district : linear
	@./linear \
	| awk '/districtbasics/ {p=0} p==1 {print} /Districtbasics/ {p=1}'

.PHONY: run_gerryempty
RUNS += run_gerryempty
run_gerryempty : linear
	@./linear \
	| awk '/gerryempty/ {p=0} p==1 {print} /Gerryempty/ {p=1}'

.PHONY: run_district5
RUNS += run_district5
run_district5 : linear
	@./linear \
	| awk '/district5/ {p=0} p==1 {print} /District5/ {p=1}'

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
