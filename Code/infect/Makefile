# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
#### Makefile for infectuous disease simulation
####
################################################################

.PHONY: info
info ::

PROGRAMS = \
    infect0 infect1 infect1a infect2 infect3 \
    mutate

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17
INCLUDES = -I${TACC_CXXOPTS_INC}
infect0 infect1  : infect_lib_simple.o
infect0.o infect1.o : infect_lib_simple.h

infect1a infect2 infect3 mutate : infect_lib.o
infect0.o infect1.o infect1a.o infect2.o infect3.o infect_lib.o mutate.o : infect_lib.h

RUNS = run_infect3
info ::
	@echo "make run_infect3 / sweep_infect3 [ -d ]"
	@echo "  supported environment variables:"
	@echo "  POPULATION= (default ${POPULATION})"
	@echo "  CONTACT= (contacts per day)"
	@echo "  PROBABILITY= ( default ${PROBABILITY})"
	@echo "  DEBUG=1 (for debug output)"
POPULATION = 10000
VACCINATION = 1
PROBABILITY = 25
DEBUG =
RANGE = 10
EXTRA =
CONTACT = 6
run_infect3 sweep_infect3 : infect3
run_infect3 :
	./infect3 -n ${POPULATION} -p ${PROBABILITY} -v ${VACCINATION} \
	          ${EXTRA} -c ${CONTACT}
sweep_infect3 :
	for c in `seq 1 ${RANGE}` ; do \
	    ./infect3 -n ${POPULATION} -p ${PROBABILITY} -v ${VACCINATION} \
	              ${EXTRA} -c $$c \
	    ; \
	done

run_mutate : mutate
	@for v in $$( seq 80 2 100 ) ; do ./mutate -v $$v ; done


include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
