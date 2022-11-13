# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
################################################################

PROGRAMS = point gridpoint pointinit pointfun pointfunref pointadd \
    pointstruct pointangle pointflip \
    ortho

LANGUAGE = CXX
include ../Make.inc

.PHONY: ${RUNS}

RUNS += run_point
.PHONY: run_point
run_point : point
	./point

RUNS += run_gridpoint
.PHONY: run_gridpoint
run_gridpoint : gridpoint
	./gridpoint

RUNS += run_pointfun
.PHONY: run_pointfun
run_pointfun : pointfun
	@( echo 5 ; echo 12 ) | ./pointfun \
	| awk '/struct pass/ {p=0} p==1 {print} /Struct Pass/ {p=1}'

RUNS += run_pointdenote
.PHONY: run_pointdenote
run_pointdenote : pointfun
	@( echo 5 ; echo 12 ) | ./pointfun \
	| awk '/struct denote/ {p=0} p==1 {print} /Struct Denote/ {p=1}'

RUNS += run_pointadd
.PHONY: run_pointadd
run_pointadd : pointadd
	@./pointadd

RUNS += run_pointangle
.PHONY: run_pointangle
run_pointangle : pointangle
	@./pointangle

RUNS += run_pointflip
.PHONY: run_pointflip
run_pointflip : pointflip
	@./pointflip

RUNS += run_ortho run_ortho_up run_ortho_trick
.PHONY: run_ortho run_ortho_up run_ortho_trick
run_ortho run_ortho_up run_ortho_dot run_ortho_trick : ortho
run_ortho :
	@./ortho
run_ortho_up :
	@./ortho \
	| awk '/up/ {p=0} p==1 {print} /Up/ {p=1}'
run_ortho_dot :
	@./ortho \
	| awk '/dot/ {p=0} p==1 {print} /Dot/ {p=1}'
run_ortho_trick :
	@./ortho \
	| awk '/trick/ {p=0} p==1 {print} /Trick/ {p=1}'

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
