# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
################################################################

PROGRAMS = readpoly findzero findzeroarray testzeroarray testzeroclass

LANGUAGE = CXX
INCLUDES = -I${TACC_CATCH2_INC}
EXTRALIBS = -L${TACC_CATCH2_LIB} -lCatch2Main -lCatch2
MODULES = catch2
include ../Make.inc

readpoly findzero : poly.o
readpoly.o poly.o findzero.o : poly.hpp
readpoly_objects = poly.o
findzero_objects = poly.o

RUNS =

RUNS += run_findzero
.PHONY: run_findzero
run_findzero : findzero
	@( echo 5 ; for i in `seq 1 6` ; do echo $$(( 1+$$i )) ; done ) \
	| ./findzero

RUNS += run_findzeroarray
.PHONY: run_findzeroarray
run_findzeroarray : findzeroarray
	@( echo 5 ; for i in `seq 1 6` ; do echo $$(( 1+$$i )) ; done ) \
	| ./findzeroarray
findzeroarray_objects = findzerolib.o
findzeroarray : findzerolib.o
findzeroarray.o findzerolib.o : findzerolib.hpp

RUNS += run_test
.PHONY: run_test
run_test : testzeroarray
	@( \
	  echo 5 ; for i in `seq 1 6` ; do echo $$(( 1+$$i )) ; done ; \
	  echo 5 ; for i in `seq 1 6` ; do echo $$(( 1+$$i )) ; done ; \
	  echo 5 ; for i in `seq 1 6` ; do echo $$(( 1+$$i )) ; done   \
	) \
	| ./testzeroarray
run_tests : testzeroarray
	@for i in `seq 1 5` ; do \
	    echo "Doing test [$$i]" \
	     && ( \
	          echo 5 ; for i in `seq 1 6` ; do echo $$(( 1+$$i )) ; done \
	        ) | ./testzeroarray "[$$i]" \
	    ; done
testzeroarray.o : findzerolib.hpp
testzeroarray : findzerolib.o
testzeroarray_objects : findzerolib.o

testzeroclass.o : findzeroclass.hpp
testzeroclass : findzeroclass.o

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
