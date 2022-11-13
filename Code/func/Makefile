# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
#### Makefile for code directory "func"
####
################################################################

PROGRAMS = twicein localparm newton passvalue passvaluelocal rhsref recur \
    swap divisible mult \
    lambdaex lambdait lambdafun lambdacapture newtonlambda mutable \
    lambdacptr lambdaexch \
    bisect1 bisect2 bisect3

WRONGS = iterate

include ../Make.inc
LANGUAGE = CXX
CPPSTANDARD = 17

RUNS =

.PHONY: run_localparm
RUNS += run_localparm
run_localparm : localparm
	@./localparm

.PHONY: run_twicein
RUNS += run_twicein
run_twicein : twicein
	@./twicein

.PHONY: run_passvalue run_passvaluelocal
RUNS += run_passvalue run_passvaluelocal
run_passvalue : passvalue
	@./passvalue
run_passvaluelocal : passvaluelocal
	@./passvaluelocal

.PHONY: run_rhsref
RUNS += run_rhsref
run_rhsref : rhsref
	@./rhsref

.PHONY: run_swap
RUNS += run_swap
run_swap : swap
	@./swap

.PHONY: run_divisible
RUNS += run_divisible
run_divisible : divisible
	@for pair in 8,3 8,4 ; do \
	  echo $$pair | awk ' BEGIN{ FS="," } { print $$1 ; print $$2 } ' \
	 | ./divisible \
	 ; done

RUNS += run_lambdadirect
run_lambdadirect : lambdaex
	@lambdaex \
	| awk '/direct/ {p=0} p==1 {print} /Direct/ {p=1}'
RUNS += run_lambdavar
run_lambdavar : lambdaex
	@lambdaex \
	| awk '/var/ {p=0} p==1 {print} /Var/ {p=1}'
RUNS += run_lambdapass
run_lambdapass : lambdaex
	@lambdaex \
	| awk '/pass/ {p=0} p==1 {print} /Pass/ {p=1}'

.PHONY: run_lambdacptr
RUNS += run_lambdacptr
run_lambdacptr : lambdacptr
	@./lambdacptr

.PHONY: run_lambdafun
RUNS += run_lambdafun
run_lambdafun : lambdafun
	@echo 7 | ./lambdafun

.PHONY: run_lambdait
RUNS += run_lambdait
run_lambdait : lambdait
	@./lambdait

.PHONY: run_lambdaexch
RUNS += run_lambdaexch
run_lambdaexch : lambdaexch
	@./lambdaexch

.PHONY: run_lambdacapture run_lambdavalue run_lambdareference
RUNS += run_lambdacapture run_lambdavalue run_lambdareference
run_lambdacapture : lambdacapture
	@./lambdacapture
run_lambdavalue : lambdacapture
	@./lambdacapture \
	| awk '/value/ {p=0} p==1 {print} /Value/ {p=1}'
run_lambdareference : lambdacapture
	@./lambdacapture \
	| awk '/reference/ {p=0} p==1 {print} /Reference/ {p=1}'

.PHONY: run_newtonlambda
RUNS += run_newtonlambda
run_newtonlambda : newtonlambda
	echo 2 | ./newtonlambda

.PHONY: run_recur
RUNS += run_recur
run_recur : recur
	@./recur

.PHONY: run_mult
RUNS += run_mult
run_mult : mult
	@( echo 7 ; echo 5 ) | ./mult

.PHONY: run_bisect1 run_bisect2 run_bisect3
RUNS += run_bisect1 run_bisect2 run_bisect3
run_bisect1 : bisect1
	@./bisect1
run_bisect2 : bisect2
	@./bisect2
run_bisect3 : bisect3
	@./bisect3

.PHONY: run_nonmutable run_yesmutable
RUNS += run_nonmutable run_yesmutable
run_nonmutable : mutable
	@./mutable \
	| awk '/nonmutable/ {p=0} p==1 {print} /NonMutable/ {p=1}'
run_yesmutable : mutable
	@./mutable \
	| awk '/yesmutable/ {p=0} p==1 {print} /YesMutable/ {p=1}'

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
