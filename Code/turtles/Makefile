# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2019-2023 Victor Eijkhout
####
#### makefile for garbage patch
####
################################################################

PROGRAMS = pacific

LANGUAGE = CXX
INCLUDES = -I${TACC_CXXOPTS_INC} -I${TACC_RANGEV3_INC} -fext-numeric-literals
MODULES = cxxopts rangev3
include ../Make.inc
CPPSTANDARD = 20
MODULES = cxxopts rangev3

RUNS =

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
