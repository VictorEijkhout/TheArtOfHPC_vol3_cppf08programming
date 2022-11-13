# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
################################################################

PROGRAMS = intchar charshift strings digits caesar \
    stringrange stringsub quote smile raw toint

LANGUAGE = CXX
include ../Make.inc

.PHONY: ${RUNS}
RUNS =

.PHONY: run_stringpush
RUNS += run_stringpush
run_stringpush : strings
	@./strings \
	| awk '/push/ {p=0} p==1 {print} /Push/ {p=1}'

.PHONY: run_stringsize
RUNS += run_stringsize
run_stringsize : strings
	@./strings \
	| awk '/size/ {p=0} p==1 {print} /Size/ {p=1}'

.PHONY: run_stringsub
RUNS += run_stringsub
run_stringsub : stringsub
	@./stringsub

.PHONY: run_stringadd
RUNS += run_stringadd
run_stringadd : strings
	@./strings \
	| awk '/add/ {p=0} p==1 {print} /Add/ {p=1}'

.PHONY: run_stringsuffix
RUNS += run_stringsuffix
run_stringsuffix : strings
	@./strings \
	| awk '/suffix/ {p=0} p==1 {print} /Suffix/ {p=1}'

.PHONY: run_intchar
RUNS += run_intchar
run_intchar :  intchar
	@./intchar

.PHONY: run_digits
RUNS += run_digits
run_digits :  digits
	echo 51 | ./digits
	echo 2136 | ./digits

.PHONY: run_quote
RUNS += run_quote
run_quote :  quote
	@./quote

.PHONY: run_smile
RUNS += run_smile
run_smile :  smile
	@./smile

.PHONY: run_toint
RUNS += run_toint
run_toint :  toint
	@./toint

.PHONY: run_stringindex stringindex
RUNS += run_stringindex
run_stringindex :  stringrange
	@./stringrange | \
	awk '/index/ {p=0} p==1 {print} /Index/ {p=1}'
.PHONY: run_stringrange
RUNS += run_stringrange
run_stringrange :  stringrange
	@./stringrange | \
	awk '/range/ {p=0} p==1 {print} /Range/ {p=1}'
.PHONY: run_stringrangeset
RUNS += run_stringrangeset
run_stringrangeset :  stringrange
	@./stringrange | \
	awk '/set/ {p=0} p==1 {print} /Set/ {p=1}'

.PHONY: run_raw1 run_raw2
RUNS += run_raw1 run_raw2
run_raw1 : raw
	@./raw \
	| awk '/raw1/ {p=0} p==1 {print} /Raw1/ {p=1}'
run_raw2 : raw
	@./raw \
	| awk '/raw2/ {p=0} p==1 {print} /Raw2/ {p=1}'

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
