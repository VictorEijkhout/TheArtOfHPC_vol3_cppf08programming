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

PROGRAMS = iter olditer each eachr customit customit2

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 20

RUNS =

RUNS += run_iter

run_iter : iter
	@./iter

RUNS += run_copy
run_copy : iter
	@./iter \
	| awk '/copy/ {p=0} p==1 {print} /Copy/ {p=1}'


RUNS += run_plusminus
run_plusminus : iter
	@./iter \
	| awk '/plusminus/ {p=0} p==1 {print} /PlusMinus/ {p=1}'

RUNS += run_erase2
run_erase2 : iter
	@./iter \
	| awk '/erase2/ {p=0} p==1 {print} /Erase2/ {p=1}'

RUNS += run_insert2
run_insert2 : iter
	@./iter \
	| awk '/insert2/ {p=0} p==1 {print} /Insert2/ {p=1}'

RUNS += run_subvectorcopy
run_subvectorcopy : iter
	@./iter \
	| awk '/subvectorcopy/ {p=0} p==1 {print} /Subvectorcopy/ {p=1} '
RUNS += run_subvectornew
run_subvectornew : iter
	@./iter \
	| awk '/subvectornew/ {p=0} p==1 {print} /Subvectornew/ {p=1} '

##
## Any / Each
##
RUNS += run_each run_eachr
run_each : each
run_eachr : eachr
run_each run_eachr :
	@./$< \
	| awk '/each/ {p=0} p==1 {print} /EACH/ {p=1}'

RUNS += run_any run_anyr run_anyc
run_any  : each
run_anyr run_anyc : eachr
run_any run_anyr :
	@./$< \
	| awk '/any/ {p=0} p==1 {print} /ANY/ {p=1}'
run_anyc :
	@./$< \
	| awk '/capture/ {p=0} p==1 {print} /CAPTURE/ {p=1}'

RUNS += run_summing run_summingr
run_summing : each
run_summingr : eachr
run_summing run_summingr :
	@./$< \
	| awk '/summing/ {p=0} p==1 {print} /SUMMING/ {p=1}'

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
