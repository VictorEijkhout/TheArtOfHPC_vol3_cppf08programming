# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-9 Victor Eijkhout
####
#### Examples of F90 subprograms
####
################################################################

PROGRAMS = contains interface printone addone plusone fact \
    readpos looppos keyword save
WRONGS = intent nocontain nocontain2 wrongcontain

include ../Make.inc
LINKER = gfortran

interface : interfunc.o

RUNS =

RUNS += run_printone
.PHONY: run_printone
run_printone : printone
	@./printone

RUNS += run_addone
.PHONY: run_addone
run_addone : addone
	@./addone

RUNS += run_plusone
.PHONY: run_plusone
run_plusone : plusone
	@./plusone

RUNS += run_fact
.PHONY: run_fact
run_fact : fact
	echo 7 | ./fact

RUNS += run_readpos
.PHONY: run_readpos
run_readpos : readpos
	@( echo -5 ; echo 0 ; echo -3.14 ; echo 2.48 ) | ./readpos

RUNS += run_nocontaintype 
.PHONY: run_nocontaintype nocontaintype
nocontaintype : nocontain2
run_nocontaintype : nocontain2
	@./nocontain2

RUNS += run_looppos
.PHONY: run_looppos
run_looppos :
	@echo "Running with the following inputs:"
	@echo
	@echo "5"
	@echo "1"
	@echo "-7.3"
	@echo
	@( echo 5 ; echo 1 ; echo -7.3 ) | ./looppos

RUNS += run_keyword
.PHONY: run_keyword
run_keyword : keyword
	@./keyword

RUNS += run_save
.PHONY: run_save
run_save : save
	@./save

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
