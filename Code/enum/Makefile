# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
#### Examples of C++ enum
####
################################################################

PROGRAMS = enum enumclass spaced
WRONGS = enumnot

LANGUAGE = CXX
include ../Make.inc

.PHONY: run_enum
RUNS += run_enum
run_enum : enum
	@./enum

.PHONY: run_spaced
RUNS += run_spaced
run_spaced : spaced
	@./spaced

.PHONY: run_enumclass
RUNS += run_enumclass
run_enumclass : enumclass
	@./enumclass

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
