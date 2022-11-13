# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018-2020 Victor Eijkhout
####
#### ways of computing pi
####
################################################################

PROGRAMS = spigot

LANGUAGE = CXX
include ../Make.inc

RUNS =

RUNS += run_spigot
.PHONY: run_spigot spigot
run_spigot : spigot
	@for n in 3 5 10 ; do \
	    echo $$n | ./spigot \
	    ; \
	done

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
