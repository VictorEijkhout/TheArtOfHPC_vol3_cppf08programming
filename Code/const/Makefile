# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-9 Victor Eijkhout
####
################################################################

PROGRAMS = privatepublic vector constref constcopy constpoint \
    mutable cache constat conststarconst

WRONG = constchange constrefget

LANGUAGE = CXX
include ../Make.inc
constperf : constperf.o constimpl.o
	g++ -o $@ constperf.o constimpl.o
constperf.o constimpl.o : constperf.h

RUNS = 

.PHONY: run_constref
RUNS += run_constref
run_constref : constref
	@./constref

.PHONY: run_constcopy
RUNS += run_constcopy
run_constcopy : constcopy
	@./constcopy

.PHONY: run_constpoint
RUNS += run_constpoint
run_constpoint : constpoint
	@./constpoint
.PHONY: run_constpoint2
RUNS += run_constpoint2
run_constpoint2 : constpoint
	@./constpoint \
	| awk '/point2/ {p=0} p==1 {print} /Point2/ {p=1}'
.PHONY: run_constpoint3
RUNS += run_constpoint3
run_constpoint3 : constpoint
	@./constpoint \
	| awk '/point3/ {p=0} p==1 {print} /Point3/ {p=1}'

.PHONY: run_constat
RUNS += run_constat
run_constat : constat
	@( echo 3 ; echo .5 ) | ./constat

.PHONY: run_conststarconst
RUNS += run_conststarconst
run_conststarconst : conststarconst
	./conststarconst


.PHONY: error_constrefget
error_constrefget : constrefget.o

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
