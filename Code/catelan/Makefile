# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019-2022 Victor Eijkhout
####
#### combinatorics examples
####
################################################################

PROGRAMS = recursive memo
WRONGS = catelist

LANGUAGE = CXX
include ../Make.inc

RUNS =

RUNS += run_recursive
.PHONY: run_recursive
run_recursive : recursive
	@./recursive

RUNS += run_memo
.PHONY: run_memo
run_memo : memo
	@./memo

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
