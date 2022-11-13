# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2020-2021 Victor Eijkhout
####
#### Makefile for Julia code directory "func"
####
################################################################

PROGRAMS = simple fillbang

LANGUAGE = J
include ../Make.inc

RUNS =

.PHONY: run_simple run_simpleone run_simplemulti
RUNS += run_simple run_simpleone run_simplemulti
run_simple : 
	@julia simple.j
run_simpleone :
	@julia simple.j \
	| awk '/one/ {p=0} p==1 {print} /One/ {p=1}'
run_simplemulti :
	@julia simple.j \
	| awk '/multi/ {p=0} p==1 {print} /Multi/ {p=1}'


include ../../makefiles/Make.clean
