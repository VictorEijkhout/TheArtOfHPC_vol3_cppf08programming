# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2023 Victor Eijkhout
####
################################################################

PROGRAMS = 0division divisiontest 2primetest 3primetestfunction  \
    4primesbyfunction 5primesbyglobal 5primesbystruct 6primesbyclass \
    primes primepairs 7goldbach 8sieve equiprimecxx \
    rangeclass rangelazy rangepred genx seqdist decomposition optfactor
WRONGS = gptclass

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 20
INCLUDES = -I${LMOD_RANGEV3_INC}
MODULES = rangev3

RUNS =

.PHONY: run_division
RUNS += run_division
run_division : divisiontest
	( echo 6 ; echo 2 ) | divisiontest
	@echo
	( echo 9 ; echo 2 ) | divisiontest

RUNS += run_class
run_class : rangeclass
	@./rangeclass

RUNS += run_lazy
run_lazy : rangelazy
	@./rangelazy

RUNS += run_genx
run_genx : genx
	@./genx | tail -n 6

RUNS += run_seqdist
run_seqdist : seqdist
	@./seqdist

RUNS += run_optfactor
run_optfactor : optfactor
	@for n in 2 5 9 53 57 ; do \
	    echo "================" \
	     && echo $$n | ./optfactor \
	    ; \
	done

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

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
