# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019-2022 Victor Eijkhout
####
#### range examples
####
################################################################

PROGRAMS = of sort filtertransform root pi transform \
    minelt sumsquare
WRONGS = 
# fibs range : missing "recursive_range"

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 20
INCLUDES=-I${HOME}/Installation/ranges/installation/include

RUNS =

.PHONY: run_of run_anyof
RUNS += run_of run_anyof
run_of : of
	@./of
run_anyof : of
	@./of \
	| awk '/any/ {p=0} p==1 {print} /ANY/ {p=1}'

RUNS += run_transform
.PHONY: run_transform
run_transform : transform
	@./transform

RUNS += run_filtertransform run_ft1 run_ft2
.PHONY: run_filtertransform run_ft1 run_ft2
run_filtertransform run_ft1 run_ft2 : filtertransform
run_filtertransform :
	@./filtertransform
run_ft1 :
	@./filtertransform \
	| awk '/one/ {p=0} p==1 {print} /One/ {p=1}'
run_ft2 :
	@./filtertransform \
	| awk '/second/ {p=0} p==1 {print} /Second/ {p=1}'

.PHONY: run_sort run_sortit
RUNS += run_sort run_sortit
run_sort : sort
	@./sort
run_sortit : sort
	@./sort \
	| awk '/itsort/ {p=0} p==1 {print} /ItSort/ {p=1}'

.PHONY: run_root
RUNS += run_root
run_root : root
	@./root

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
