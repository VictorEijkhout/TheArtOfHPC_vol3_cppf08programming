# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019-2023 Victor Eijkhout
####
#### range examples
####
################################################################

PROGRAMS = of sort filtertransform root pi collatz \
    minelt sumsquare zip subrange infinite
WRONGS = adjacent
# adjacent: missing in std & range-v3
# fibs range : missing "recursive_range"
MODULES = fmtlib rangev3

LANGUAGE = CXX
include ../Make.inc
INCLUDES = -I${TACC_RANGEV3_INC} -I${TACC_FMTLIB_INC}
EXTRALIBS = -L${TACC_FMTLIB_LIB} -lfmt
MODULES = fmtlib rangev3
RPATH = ${TACC_FMTLIB_LIB}
CPPSTANDARD = 23

RUNS =

RUNS += run_of run_anyof
run_of : of
	@./of
run_anyof : of
	@./of \
	| awk '/any/ {p=0} p==1 {print} /ANY/ {p=1}'

RUNS += run_transform
run_transform : collatz
	@./collatz

RUNS += run_filtertransform run_ft1 run_ft2
run_filtertransform run_ft1 run_ft2 : filtertransform
run_filtertransform :
	@./filtertransform
run_ft1 :
	@./filtertransform \
	| awk '/one/ {p=0} p==1 {print} /One/ {p=1}'
run_ft2 :
	@./filtertransform \
	| awk '/second/ {p=0} p==1 {print} /Second/ {p=1}'

RUNS += run_sort run_sortit
run_sort : sort
	@./sort
run_sortit : sort
	@./sort \
	| awk '/itsort/ {p=0} p==1 {print} /ItSort/ {p=1}'

run_zip : zip
	@./zip \
	| awk '/zip/ {p=0} p==1 {print} /Zip/ {p=1}'

RUNS += run_root
run_root : root
	@./root

RUNS += run_infinite
run_infinite : infinite
	@./infinite

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
