# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2023 Victor Eijkhout
####
#### makefile for array/vector programs
####
################################################################

PROGRAMS = stdarray toarray \
    staticbound staticinit staticsize shortvector \
    dynamicinit dynamicmax dynamicscale \
    assign assignoutofbound assignoutofstatic \
    arraynew arraystd arraygrind arraydata \
    rangemax rangescale normloop idxmax vecidxmax oddevensplit rangedenote \
    alloc arrayprint arraypass segmentation \
    classvector vectorpassnot vectorpassref vectorreturn \
    vectorend vectorsorted vectorcopy vectorrangecopy vectorrangeref \
    arraytime twod contig matrix matrixclass matrix12 \
    getindex1 getindex2 getindex3 \
    cvector collapse1 collapse2 heaptime

WRONGS = arraysize at carray

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 20

RUNS =

RUNS += run_staticinit
run_staticinit : staticinit
	@./staticinit

RUNS += run_staticsize
run_staticsize : staticsize
	@./staticsize

RUNS += run_dynamicinit
run_dynamicinit : dynamicinit
	@./dynamicinit

RUNS += run_arraymaxidx
run_arraymaxidx : idxmax
	@./idxmax | grep "Max:"

RUNS += run_rangemax
run_rangemax : rangemax
	@./rangemax

RUNS += run_rangedenote
run_rangedenote : rangedenote
	@./rangedenote

RUNS += run_dynamicmax
run_dynamicmax : dynamicmax
	@./dynamicmax

RUNS += run_rangescale
run_rangescale : rangescale
	@./rangescale 

RUNS += run_dynamicscale
run_dynamicscale : dynamicscale
	@./dynamicscale 

RUNS += run_idxmax
run_idxmax : idxmax
	@./idxmax

RUNS += run_vecidxmax
run_vecidxmax : vecidxmax
	@./vecidxmax

RUNS += run_normloop
run_normloop : normloop
	@./normloop

RUNS += run_vectorcopy
run_vectorcopy : vectorcopy
	@./vectorcopy

RUNS += run_classvector
run_classvector : classvector
	@echo 5 | ./classvector

RUNS += run_assignatfun run_assignbracket
run_assignatfun : assign
	@./assign \
	| awk '/atfun/ {p=0} p==1 {print} /Atfun/ {p=1}'
run_assignbracket : assign
	@./assign \
	| awk '/bracket/ {p=0} p==1 {print} /Bracket/ {p=1}'

RUNS += run_assignoutofboundatfun run_assignoutofboundbracket
run_assignoutofboundatfun : assignoutofbound
	@./assignoutofbound \
	| awk '/atfun/ {p=0} p==1 {print} /Atfun/ {p=1}'
run_assignoutofboundbracket : assignoutofbound
	@./assignoutofbound 2>/dev/null \
	| awk '/bracket/ {p=0} p==1 {print} /Bracket/ {p=1}'

RUNS += run_vectorend run_vectorenditerator
run_vectorend : vectorend
	@./vectorend \
	| awk '/bracket/ {p=0} p==1 {print} /Bracket/ {p=1}'
run_vectorenditerator : vectorend
	@./vectorend \
	| awk '/iterator/ {p=0} p==1 {print} /Iterator/ {p=1}'

RUNS += run_vectorpassnot
run_vectorpassnot : vectorpassnot
	@./vectorpassnot

RUNS += run_vectorpassref
run_vectorpassref : vectorpassref
	@./vectorpassref

RUNS += run_vectorreturn
run_vectorreturn : vectorreturn
	@./vectorreturn

RUNS += run_vectorrangecopy 
run_vectorrangecopy : vectorrangecopy
	@./vectorrangecopy

RUNS += run_vectorrangeref
run_vectorrangeref : vectorrangeref
	@./vectorrangeref

RUNS += run_matrix run_matrixsum
run_matrix : matrix
	@./matrix \
	| awk '/setget/ {p=0} p==1 {print} /SetGet/ {p=1}'
run_matrixsum : matrix
	@./matrix \
	| awk '/sum/ {p=0} p==1 {print} /Sum/ {p=1}'

RUNS += run_matrix12
run_matrix12 : matrix
	@rm -f matrix12 \
	 && echo "Compiling with optlevel 1" \
	 && make matrix12 OPTLEVEL=1
	@./matrix12 \
	| grep -v checking

RUNS += run_cvector
run_cvector : cvector
	@./cvector

RUNS += run_carray
run_carray : carray
	@./carray

RUNS += run_heaptime
run_heaptime : heaptime
	@./heaptime

RUNS += run_segmentation
run_segmentation : segmentation
	-@ ${SHELL} -c "./segmentation || echo" >segmentation.err 2>&1
	@tail segmentation.err

.PHONY: ${RUNS}

no_run_seg :
	2>segmentation.err | tail -n 10
	@if [ -f segmentation.err ] ; then \
	     cat segmentation.err ; fi
	@echo "Segmentation fault: 11"

clean ::
	@rm -f *.err

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
