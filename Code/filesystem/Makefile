# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
#### makefile C++17 filesystem
####
################################################################

PROGRAMS = 
WRONGS = filesize

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17
EXTRALIBS = 
#-lc++experimental

RUNS = 

.PHONY: run_filesize
RUNS += run_filesize
run_filesize : filesize
	@/bin/rm -f testfile \
	&& echo "foo" > testfile \
	&& ./filesize
clean ::
	@rm -f testfile

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
