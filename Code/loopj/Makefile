# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2020-2021 Victor Eijkhout
####
#### Julia loops
####
################################################################

PROGRAMS = loop hellocount

LANGUAGE = J
include ../Make.inc
LINKER = julia

RUNS =

RUNS += run_loop
.PHONY: run_loop
run_loop : 
	@julia loop.j

RUNS += run_hello
.PHONY: run_hello
run_hello : 
	@echo 17 | julia hellocount.j
include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
