# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2020 Victor Eijkhout
####
#### makefile for octree N-body
####
################################################################

PROGRAMS = octree visit

include ../Make.inc
LANGUAGE = CXX

RUNS =

.PHONY: run_octree
RUNS += run_octree
run_octree : octree
	@./octree
octree : octree.o octree_lib.o
octree.o octree_lib.o : octree_lib.h
include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
