# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2020 Victor Eijkhout
####
################################################################

PROGRAMS = ostream tuple iter reduce \
    printeach optional limits

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

##
## regression runs
##
RUNS =

.PHONY: run_tuple
RUNS += run_tuple
run_tuple : tuple
	@for x in 2 -2 ; do echo $$x | ./tuple ; done

.PHONY: run_iter
RUNS += run_iter
run_iter : iter
	@./iter \
	| awk '/iter/ {p=0} p==1 {print} /Iter/ {p=1}'
.PHONY: run_erase
RUNS += run_erase
run_erase : iter
	@./iter \
	| awk '/..erase/ {p=0} p==1 {print} /Erase../ {p=1}'

.PHONY: run_accumulate
RUNS += run_accumulate
run_accumulate : reduce
	@./reduce \
	| awk '/.. accumulate/ {p=0} p==1 {print} /Accumulate ../ {p=1}'
.PHONY: run_product
RUNS += run_product
run_product : reduce
	@./reduce \
	| awk '/.. product/ {p=0} p==1 {print} /Product ../ {p=1}'
.PHONY: run_classacc
RUNS += run_classacc
run_classacc : reduce
	@./reduce \
	| awk '/.. class/ {p=0} p==1 {print} /Class ../ {p=1}'

.PHONY: run_printeach
RUNS += run_printeach
run_printeach : printeach
	@./printeach \
	| awk '/print/ {p=0} p==1 {print} /Print/ {p=1}'
.PHONY: run_counteach
RUNS += run_counteach
run_counteach : printeach
	@./printeach \
	| awk '/count/ {p=0} p==1 {print} /Count/ {p=1}'

.PHONY: run_optional
RUNS += run_optional
run_optional : optional
	@./optional

.PHONY: run_limits run_eps
RUNS += run_limits run_eps
run_limits run_eps : limits
run_limits :
	@./limits \
	| awk '/limit/ {p=0} p==1 {print} /Limit/ {p=1}'
run_eps :
	@./limits \
	| awk '/macheps/ {p=0} p==1 {print} /Macheps/ {p=1}'
include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
