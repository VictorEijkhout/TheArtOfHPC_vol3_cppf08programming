# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018-2023 Victor Eijkhout
####
#### iterator stuff
####
################################################################

PROGRAMS = iter olditer each customit customit2

LANGUAGE = CXX
include ../Make.inc

RUNS =

RUNS += run_iter
.PHONY: run_iter 
run_iter : iter
	@./iter

RUNS += run_copy
.PHONY: run_copy 
run_copy : iter
	@./iter \
	| awk '/copy/ {p=0} p==1 {print} /Copy/ {p=1}'


RUNS += run_plusminus
.PHONY: run_plusminus 
run_plusminus : iter
	@./iter \
	| awk '/plusminus/ {p=0} p==1 {print} /PlusMinus/ {p=1}'

RUNS += run_erase2
.PHONY: run_erase2 
run_erase2 : iter
	@./iter \
	| awk '/erase2/ {p=0} p==1 {print} /Erase2/ {p=1}'

RUNS += run_insert2
.PHONY: run_insert2 
run_insert2 : iter
	@./iter \
	| awk '/insert2/ {p=0} p==1 {print} /Insert2/ {p=1}'

RUNS += run_subvector
.PHONY: run_subvector 
run_subvector : iter
	@./iter \
	| awk '/subvector/ {p=0} p==1 {print} /Subvector/ {p=1} '

RUNS += run_each
.PHONY: run_each 
run_each : each
	@./each \
	| awk '/each/ {p=0} p==1 {print} /EACH/ {p=1}'

RUNS += run_any
.PHONY: run_any 
run_any : each
	@./each \
	| awk '/any/ {p=0} p==1 {print} /ANY/ {p=1}'

RUNS += run_summing
.PHONY: run_summing 
run_summing : each
	@./each \
	| awk '/summing/ {p=0} p==1 {print} /SUMMING/ {p=1}'

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
