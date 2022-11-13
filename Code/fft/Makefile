# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
################################################################

PROGRAMS = fft fftcplx
LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 20
EXTRA_OPTIONS = -DCPPSTANDARD${CPPSTANDARD}

RUNS += run_fft
.PHONY: run_fft
run_fft : fft
	@./fft

RUNS += run_fftcplx
.PHONY: run_fftcplx
run_fftcplx : fftcplx
	@./fftcplx

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
