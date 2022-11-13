# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
################################################################

PROGRAMS = particles

LANGUAGE = F
include ../Make.inc

RUNS =

RUNS += run_particles
.PHONY: run_particles
run_particles :: particles
	@./particles < particle.in

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
