################################################################
################################################################
####
#### This Makefile belong with the sources
#### for Introduction to Scientific Programming
#### by Victor Eijkhout
####
#### copyright 2020-2021 Victor Eijkhout
####
#### makefile for fortran issues
####
################################################################
################################################################

info ::
	@echo

PROGRAM = inttypes
PROGRAMS = inttypes deftypes plustype

include ../Make.inc
LANGUAGE = F

RUNS = 

RUNS += run_int
.PHONY: run_int
run_int : inttypes
	@./inttypes

RUNS += run_def
.PHONY: run_def
run_def : deftypes
	@./deftypes

RUNS += run_plus
.PHONY: run_plus
run_plus : plustype
	@./plustype

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
clean :: 
	@rm -f ${PROGRAMS}
