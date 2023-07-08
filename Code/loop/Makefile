# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018-2023 Victor Eijkhout
####
#### looping exercises
####
################################################################

PROGRAMS = pyth factor vecerr \
    bag rangeconst distance plusplus horse sumsquares \
    findmin whileinit pow iterclass
WRONGS = vecexc staterr 

LANGUAGE = CXX
MODE = omp
include ../Make.inc

RUNS =

RUNS += run_distance
run_distance : distance
	@./distance

# staterr : compilation bombs
RUNS += run_staterr
run_staterr : staterr

# vecerr : error undetected
RUNS += run_vecerr
run_vecerr : vecerr
	@./vecerr

RUNS += run_findmin
run_findmin : findmin
	@./findmin

RUNS += run_staterr
run_staterr : staterr
	@./staterr

# vecexc : error causes exception
RUNS += run_vecexc
run_vecexc : vecexc
	@./vecexc

RUNS += run_bagfind run_bagany
bagfind bagany : bag
run_bagfind : bag
	@./bag \
	| awk '/find/ {p=0} p==1 {print} /Find/ {p=1}'
run_bagany : bag
	@./bag \
	| awk '/any/ {p=0} p==1 {print} /Any/ {p=1}'

RUNS += run_plusplus
run_plusplus : plusplus
	@./plusplus \
	| awk '/test/ {p=0} p==1 {print} /Test/ {p=1}'

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
