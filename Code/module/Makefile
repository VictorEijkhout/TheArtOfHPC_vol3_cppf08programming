# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2021 Victor Eijkhout
####
#### Examples of F90 modules and sub modules
####
################################################################

PROGRAMS = modprog protect
WRONGS = 

include ../Make.inc
LANGUAGE = F

RUNS =

# extra link:
modprog : smodone.o modone.o
# compile order
modprog.o : smodone.o
modprog.o smodone.o : modone.o

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
