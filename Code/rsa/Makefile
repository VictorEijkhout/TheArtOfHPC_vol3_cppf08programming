# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018/9 Victor Eijkhout
####
#### makefile for crypto exercises
####
################################################################

PROGRAMS = trial rsa

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 14

RUNS =

.PHONY: run_trial
RUNS += run_trial
run_trial : trial
	@./trial

.PHONY: run_rsa
RUNS += run_rsa
info ::
	@echo "  for run_rsa: LOWPRIME=... default=${LOWPRIME}"
LOWPRIME = 50
run_rsa : rsa
	( echo ${LOWPRIME} ) | ./rsa

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
