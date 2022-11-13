# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
#### F90 programs for strings
####
################################################################

PROGRAMS = quote posone convert readwrite

LANGUAGE = F
include ../Make.inc

RUNS =

RUNS += run_quote
.PHONY: run_quote
run_quote : quote
	@./quote \
	| awk ' /quote./ { p=0 } p==1 {print} /Quote:/ { p=1 }'

RUNS += run_concat
.PHONY: concat run_concat
concat :
run_concat : quote
	@./quote \
	| awk ' /concat./ { p=0 } p==1 {print} /Concat:/ { p=1 }'

RUNS += run_strlen
.PHONY: strlen run_strlen
strlen :
run_strlen : quote
	@./quote \
	| awk ' /strlen./ { p=0 } p==1 {print} /Strlen:/ { p=1 }'

RUNS += run_posone
.PHONY: run_posone
run_posone : posone
	@./posone

RUNS += run_lower run_ascii
.PHONY: run_lower run_ascii
run_lower run_ascii : convert
run_lower :
	@./convert \
	 | awk '/islower/ {p=0} p==1 {print} /IsLower/ {p=1}'
run_ascii :
	@./convert \
	 | awk '/ascii/ {p=0} p==1 {print} /Ascii/ {p=1}'

RUNS += run_date run_slash
.PHONY: run_date run_slash
run_date : readwrite
	@./readwrite \
	 | awk '/rw/ {p=0} p==1 {print} /RW/ {p=1}'
run_slash : readwrite
	@./readwrite \
	 | awk '/slash/ {p=0} p==1 {print} /Slash/ {p=1}'

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
