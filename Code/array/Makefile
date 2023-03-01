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

info ::

LANGUAGE = CXX
CPPSTANDARD = 17
include ../Make.inc

RUNS =

.PHONY: run_staticinit
RUNS += run_staticinit
run_staticinit : staticinit
	@./staticinit

.PHONY: run_staticsize
RUNS += run_staticsize
run_staticsize : staticsize
	@./staticsize

.PHONY: run_dynamicinit
RUNS += run_dynamicinit
run_dynamicinit : dynamicinit
	@./dynamicinit

.PHONY: run_arraymaxidx
RUNS += run_arraymaxidx
run_arraymaxidx : idxmax
	@./idxmax | grep "Max:"

.PHONY: run_rangemax
RUNS += run_rangemax
run_rangemax : rangemax
	@./rangemax

.PHONY: run_rangedenote
RUNS += run_rangedenote
run_rangedenote : rangedenote
	@./rangedenote

.PHONY: run_dynamicmax
RUNS += run_dynamicmax
run_dynamicmax : dynamicmax
	@./dynamicmax

.PHONY: run_rangescale
RUNS += run_rangescale
run_rangescale : rangescale
	@./rangescale 

.PHONY: run_dynamicscale
RUNS += run_dynamicscale
run_dynamicscale : dynamicscale
	@./dynamicscale 

.PHONY: run_idxmax
RUNS += run_idxmax
run_idxmax : idxmax
	@./idxmax

.PHONY: run_vecidxmax
RUNS += run_vecidxmax
run_vecidxmax : vecidxmax
	@./vecidxmax

.PHONY: run_normloop
RUNS += run_normloop
run_normloop : normloop
	@./normloop

.PHONY: run_vectorcopy
RUNS += run_vectorcopy
run_vectorcopy : vectorcopy
	@./vectorcopy

.PHONY: run_classvector
RUNS += run_classvector
run_classvector : classvector
	@echo 5 | ./classvector

.PHONY: run_assignatfun run_assignbracket
RUNS += run_assignatfun run_assignbracket
run_assignatfun : assign
	@./assign \
	| awk '/atfun/ {p=0} p==1 {print} /Atfun/ {p=1}'
run_assignbracket : assign
	@./assign \
	| awk '/bracket/ {p=0} p==1 {print} /Bracket/ {p=1}'

.PHONY: run_assignoutofboundatfun run_assignoutofboundbracket
RUNS += run_assignoutofboundatfun run_assignoutofboundbracket
run_assignoutofboundatfun : assignoutofbound
	@./assignoutofbound \
	| awk '/atfun/ {p=0} p==1 {print} /Atfun/ {p=1}'
run_assignoutofboundbracket : assignoutofbound
	@./assignoutofbound 2>/dev/null \
	| awk '/bracket/ {p=0} p==1 {print} /Bracket/ {p=1}'

.PHONY: run_vectorend run_vectorenditerator
RUNS += run_vectorend run_vectorenditerator
run_vectorend : vectorend
	@./vectorend \
	| awk '/bracket/ {p=0} p==1 {print} /Bracket/ {p=1}'
run_vectorenditerator : vectorend
	@./vectorend \
	| awk '/iterator/ {p=0} p==1 {print} /Iterator/ {p=1}'

.PHONY: run_vectorpassnot
RUNS += run_vectorpassnot
run_vectorpassnot : vectorpassnot
	@./vectorpassnot

.PHONY: run_vectorpassref
RUNS += run_vectorpassref
run_vectorpassref : vectorpassref
	@./vectorpassref

.PHONY: run_vectorreturn
RUNS += run_vectorreturn
run_vectorreturn : vectorreturn
	@./vectorreturn

.PHONY:  run_vectorrangecopy 
RUNS += run_vectorrangecopy 
run_vectorrangecopy : vectorrangecopy
	@./vectorrangecopy

.PHONY: run_vectorrangeref 
RUNS += run_vectorrangeref
run_vectorrangeref : vectorrangeref
	@./vectorrangeref

.PHONY: run_matrix run_matrixsum
RUNS += run_matrix run_matrixsum
run_matrix : matrix
	@./matrix \
	| awk '/setget/ {p=0} p==1 {print} /SetGet/ {p=1}'
run_matrixsum : matrix
	@./matrix \
	| awk '/sum/ {p=0} p==1 {print} /Sum/ {p=1}'

.PHONY: run_matrix12
RUNS += run_matrix12
run_matrix12 : matrix
	@rm -f matrix12 \
	 && echo "Compiling with optlevel 1" \
	 && make matrix12 OPTLEVEL=1
	@./matrix12 \
	| grep -v checking

.PHONY: run_cvector
RUNS += run_cvector
run_cvector : cvector
	@./cvector

.PHONY: run_carray
RUNS += run_carray
run_carray : carray
	@./carray

.PHONY: run_heaptime
RUNS += run_heaptime
run_heaptime : heaptime
	@./heaptime

.PHONY: run_segmentation
RUNS += run_segmentation
run_segmentation : segmentation
	-@ ${SHELL} -c "./segmentation || echo" >segmentation.err 2>&1
	@tail segmentation.err

no_run_seg :
	2>segmentation.err | tail -n 10
	@if [ -f segmentation.err ] ; then \
	     cat segmentation.err ; fi
	@echo "Segmentation fault: 11"

clean ::
	@rm -f *.err

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
