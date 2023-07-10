# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2020 Victor Eijkhout
####
#### Makefile for neural net simulation
####
################################################################

.PHONY: info
info ::

PROGRAMS = \
    separate interval
WRONGS = layer net 
${PROGRAMS} : mllib.o

$(patsubst %,%.o,${PROGRAMS}) : ml.hpp
mllib.o : ml.hpp mllib.cpp

LANGUAGE = CXX
include ../Make.inc
INCLUDES = -I${TACC_CXXOPTS_INC}
MODULES = cxxopts

#RUNS += run_layer
run_layer : layer
	@./layer

#RUNS += run_net
run_net : net
	@./net

RUNS += run_separate
run_separate : separate
	@./separate

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
