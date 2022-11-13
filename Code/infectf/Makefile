# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
################################################################

.PHONY: info
info ::

PROGRAMS = contact

infect1_objects = infect_lib.o
infect2_objects = infect_lib.o
infect3_objects = infect_lib.o
infect0 infect1 infect2 infect3 : infect_lib.o

infect0.o infect1.o infect1a.o infect2.o infect3.o infect_lib.o : infect_lib.h

LANGUAGE = F
include ../Make.inc

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
