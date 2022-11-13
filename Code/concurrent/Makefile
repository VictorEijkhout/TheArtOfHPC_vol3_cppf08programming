# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-9 Victor Eijkhout
####
#### examples for concurrency
####
################################################################

PROGRAMS = two omp thread dekker


LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17
OPTIONS = ${OMP_OPTIONS}

RUNS = 

.PHONY: run_omp_old run_omp_consist run_omp_relax run_omp_release
RUNS += run_omp_old run_omp_consist run_omp_relax run_omp_release
run_omp_old run_omp_consist run_omp_relax run_omp_release: omp
run_omp_old :
	@export OMP_NUM_THREADS=2 \
	&& for i in `seq 1 100` ; do \
	     ./omp \
	     | awk '/old/ {p=0} p==1 {print} /Old/ {p=1}' \
	     ; \
	   done \
	   | sort -u
run_omp_consist :
	@export OMP_NUM_THREADS=2 \
	&& for i in `seq 1 100` ; do \
	     ./omp \
	     | awk '/new/ {p=0} p==1 {print} /New/ {p=1}' \
	     ; \
	   done \
	   | sort -u
run_omp_relax :
	@export OMP_NUM_THREADS=2 \
	&& for i in `seq 1 100` ; do \
	     ./omp \
	     | awk '/relax/ {p=0} p==1 {print} /Relax/ {p=1}' \
	     ; \
	   done \
	   | sort -u
run_omp_release :
	@export OMP_NUM_THREADS=2 \
	&& for i in `seq 1 100` ; do \
	     ./omp \
	     | awk '/release/ {p=0} p==1 {print} /Release/ {p=1}' \
	     ; \
	   done \
	   | sort -u


.PHONY: run_thread_old run_thread_consist run_thread_relax run_thread_release
RUNS += run_thread_old run_thread_consist run_thread_relax run_thread_release
run_thread_old run_thread_consist run_thread_relax run_thread_release: thread
run_thread_old :
	@export THREAD_NUM_THREADS=2 \
	&& for i in `seq 1 100` ; do \
	     ./thread \
	     | awk '/old/ {p=0} p==1 {print} /Old/ {p=1}' \
	     ; \
	   done \
	   | sort -u
run_thread_consist :
	@export THREAD_NUM_THREADS=2 \
	&& for i in `seq 1 100` ; do \
	     ./thread \
	     | awk '/new/ {p=0} p==1 {print} /New/ {p=1}' \
	     ; \
	   done \
	   | sort -u
run_thread_relax :
	@export THREAD_NUM_THREADS=2 \
	&& for i in `seq 1 100` ; do \
	     ./thread \
	     | awk '/relax/ {p=0} p==1 {print} /Relax/ {p=1}' \
	     ; \
	   done \
	   | sort -u
run_thread_release :
	@export THREAD_NUM_THREADS=2 \
	&& for i in `seq 1 100` ; do \
	     ./thread \
	     | awk '/release/ {p=0} p==1 {print} /Release/ {p=1}' \
	     ; \
	   done \
	   | sort -u


include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
