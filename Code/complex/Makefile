# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
################################################################

PROGRAMS = veccomplex

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

##
## regression runs
##
RUNS =

RUNS += run_vec
.PHONY: run_vec
run_vec : veccomplex
	@echo 1000000 \
	| veccomplex \
	| awk '/sum/ {p=0} p==1 {print} /Sum/ {p=1}'

RUNS += run_veccomplextest
N = 100000
FP_KEYWORD_intel = -fp-model
FP_SEP_intel = 40
FP_MODEL_intel = strict fast

FP_KEYWORD_gcc =
FP_SEP_gcc =
FP_MODEL_gcc = -fno-unsafe-math-optimizations -funsafe-math-optimizations

FP_KEYWORD = ${FP_KEYWORD_${LMOD_FAMILY_COMPILER}}
FP_SEP = ${FP_SEP_${LMOD_FAMILY_COMPILER}}
FP_MODEL = ${FP_MODEL_${LMOD_FAMILY_COMPILER}}
run_veccomplextest :
	@for opt in ${FP_MODEL} ; do \
	    echo "$$opt" \
	     && make --no-print-directory clean \
	     && make --no-print-directory OPTIONS="${FP_KEYWORD}$$( echo _ | tr _ \\${FP_SEP} )$${opt}" \
	            OPTLEVEL=${OPTLEVEL} ECHO=1 veccomplex \
	     && echo $N | ./veccomplex \
	    ; \
	done

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
