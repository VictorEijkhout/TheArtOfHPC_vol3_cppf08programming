# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
#### Examples of basic F90 constructs
####
################################################################

PROGRAMS = emptyprog e0 d0 shortcut select \
    complex complexf08 quadratic div stop stopreturn \
    kind command ieee iso binding

LANGUAGE = F
include ../Make.inc

RUNS =

RUNS += run_d0
info ::
	@echo "   ( for d0: VALUE is the input number )"
.PHONY: run_d0
VALUE = 3.14
run_d0 : d0
	@( echo ${VALUE} ; echo ${VALUE} ) | ./d0 \
	    | awk '/thereandback/ {p=0} p==1 {print} /ThereAndBack/ {p=1}'

RUNS += run_stop
.PHONY: run_stop
run_stop : stop
	@./stop

RUNS += run_return
.PHONY: run_return
run_return : stopreturn
	./stopreturn || code=$$? \
	 && echo Return code is $$code

RUNS += run_e0
.PHONY: run_e0
run_e0 : e0
	@./e0

RUNS += run_kind
.PHONY: run_kind
run_kind : kind
	@./kind

RUNS += run_complex
.PHONY: run_complex
run_complex : complex
	@./complex | sed 's/^ *//'

RUNS += run_quadratic
.PHONY: run_quadratic
run_quadratic : quadratic
	@./quadratic | sed 's/^ *//'

RUNS += run_complexf08
.PHONY: run_complexf08
run_complexf08 : complexf08
	@./complexf08 | sed 's/^ *//'

RUNS += run_idiv run_fdiv
.PHONY: run_idiv run_fdiv idiv fdiv
idiv fdiv :
run_idiv : div
	@./div \
	| awk '/idiv/ {p=0} p==1 {print} /Idiv/ {p=1}'
run_fdiv : div
	@./div \
	| awk '/fdiv/ {p=0} p==1 {print} /Fdiv/ {p=1}'

RUNS += run_ieee
.PHONY: run_ieee
run_ieee : ieee
	@./ieee

RUNS += run_binding
.PHONY: run_binding
run_binding : binding
	@./binding

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
