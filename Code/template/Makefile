# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017/8 Victor Eijkhout
####
################################################################

PROGRAMS = example1 example2 eps max cl3
WRONGS = 

LANGUAGE = CXX
include ../Make.inc

RUNS =

RUNS += run_example1 run_example1i5 run_example1f314
.PHONY: run_example1 run_example1i5 run_example1f314
run_example1 run_example1i5 run_example1f314 : example1
run_example1 :
	@./example1
run_example1i5 :
	@./example1 \
	| awK '/storei5/ {p=0} p==1 {print} /StoreI5/ {p=1}'
run_example1f314 :
	@./example1 \
	| awK '/storef314/ {p=0} p==1 {print} /StoreF314/ {p=1}'

RUNS += run_example2
.PHONY: run_example2
run_example2 : example2
	@./example2

RUNS += run_eps
.PHONY: run_eps
run_eps : eps
	@./eps

RUNS += run_max
.PHONY: run_max
run_max : max
	@./max

sep : sep_main.o sep_impl.o
	${LINKER} -o $@ $^

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
