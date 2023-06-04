# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2023 Victor Eijkhout
####
################################################################

PROGRAMS = newton  newton-fun newton-lambda \
	newton-double newton-complex lambda-complex \
	newton-template newton-templatefun
WRONGS = newton-concept

LANGUAGE = CXX
include ../Make.inc
# redefine cxx standard:
CPPSTANDARD = 20

RUNS = run_newton run_fun run_lambda
.PHONY: run_newton run_fun run_lambda
run_newton : newton
	@./newton
run_fun : newton-fun
	@./newton-fun
run_lambda : newton-lambda
	@./newton-lambda

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
