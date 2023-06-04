# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
#### makefile for auto examples
####
################################################################

PROGRAMS = plainget refget autofun autoref 

WRONGS = constrefget

LANGUAGE = CXX
include ../Make.inc

RUNS = 

.PHONY: run_plainget
RUNS += run_plainget
run_plainget : plainget
	@./plainget

.PHONY: run_refget
RUNS += run_refget
run_refget : refget
	@./refget

.PHONY: run_autofun
RUNS += run_autofun
run_autofun : autofun
	@./autofun

.PHONY: error_constrefget
error_constrefget :
	-@rm -f constrefget && \
	make constrefget

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
