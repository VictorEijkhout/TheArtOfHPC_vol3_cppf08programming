# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
################################################################

PROGRAMS = newton newton-fun newton-lambda

LANGUAGE = CXX
include ../Make.inc

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
