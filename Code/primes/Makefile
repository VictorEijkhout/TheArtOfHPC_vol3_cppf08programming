# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
################################################################

PROGRAMS = 0division divisiontest 2primetest 3primetestfunction  \
    4primesbyfunction 5primesbyglobal 5primesbystruct 6primesbyclass \
    primes primepairs 7goldbach 8sieve equiprimecxx \
    range genx seqdist decomposition optfactor

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

RUNS =

.PHONY: run_division
RUNS += run_division
run_division : divisiontest
	( echo 6 ; echo 2 ) | divisiontest
	@echo
	( echo 9 ; echo 2 ) | divisiontest

.PHONY: run_range
RUNS += run_range
run_range : range
	@./range

.PHONY: run_genx
RUNS += run_genx
run_genx : genx
	@./genx | tail -n 6

.PHONY: run_seqdist
RUNS += run_seqdist
run_seqdist : seqdist
	@./seqdist

.PHONY: run_optfactor
RUNS += run_optfactor
run_optfactor : optfactor
	@for n in 2 5 9 53 57 ; do \
	    echo "================" \
	     && echo $$n | ./optfactor \
	    ; \
	done

.PHONY: run_decomposition run_decomposition26 run_decomposition180
RUNS += run_decomposition run_decomposition26 run_decomposition180
run_decomposition run_decomposition26 run_decomposition180 : decomposition
run_decomposition :
	@./decomposition
run_decomposition26 :
	@./decomposition \
	| awk '/i26/ {p=0} p==1 {print} /I26/ {p=1}'
run_decomposition180 :
	@./decomposition \
	| awk '/i180/ {p=0} p==1 {print} /I180/ {p=1}'
include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
