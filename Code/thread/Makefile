# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
################################################################

PROGRAMS = hello async atomic block even promise race

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

##
## regression runs
##
RUNS =

RUNS += run_hello run_hellomess run_hellonice
.PHONY: run_hello run_hellomess run_hellonice
run_hello run_hellomess run_hellonice : hello
run_hello :
	@./hello
run_hellomess :
	@./hello \
	| awk '/alltogether/ {p=0} p==1 {print} /AllTogether/ {p=1}'
run_hellonice :
	@./hello \
	| awk '/orderly/ {p=0} p==1 {print} /Orderly/ {p=1}'

RUNS += run_block
.PHONY: run_block
run_block : block
	@./block

RUNS += run_promisewait
.PHONY: run_promisewait
run_promisewait : promise
	@./promise \
	| awk '/timeout/ {p=0} p==1 {print} /Timeout/ {p=1}'

RUNS += run_race run_atomic
.PHONY: run_race run_atomic
run_race :: race
run_atomic :: atomic
run_race run_atomic ::
	@ program=$@ && program=$${program##run_} \
	 && echo "Three runs of <<$$program>>;" \
	 && echo "printing first lines only:" \
	 && for i in 1 2 3 ; do \
	        echo "----" \
	        && ./$$program \
	           | awk 'BEGIN {m=0; t=0;} \
	                   /Main/ && m==0 {print; m=1} \
	                   /Thread/ && t==0 {print; t=1} \
	                   /Final/ {print} \
	                   /Runtime/ {print} \
	                 ' \
	        ; done


include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
