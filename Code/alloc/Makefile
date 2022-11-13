# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
#### Custom allocators
####
################################################################

PROGRAMS = alignmabille
WRONGS = alignchristos align17

LANGUAGE = CXX
CPPSTANDARD = 17
include ../Make.inc

.PHONY: run_mabille
RUNS += run_mabille
mabille : alignmabille
run_mabille : alignmabille
	@./alignmabille

.PHONY: run_christos
## RUNS += run_christos
christos : alignchristos
run_christos : alignchristos
	@./alignchristos

.PHONY: run_align17
## RUNS += run_align17
run_align17 : align17
	@./align17

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
