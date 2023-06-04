# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
####
################################################################

PROGRAMS = address any pointx twopoint pointy printfpoint coutpoint \
    arrayaddr arraypass starconst \
    ptr0 ptr1 ptr2 ptr3 pointrectangle dynrectangle \
    cintpointer ptrdouble


LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

RUNS = 

.PHONY: run_address
RUNS += run_address
run_address : address
	@./address

.PHONY: run_arrayaddr
RUNS += run_arrayaddr
run_arrayaddr : arrayaddr
	@./arrayaddr

.PHONY: run_arraypass
RUNS += run_arraypass
run_arraypass : arraypass
	@./arraypass

.PHONY: run_pointx
RUNS += run_pointx
run_pointx : pointx
	@./pointx

.PHONY: run_starconst run_starconst1
RUNS += run_starconst run_starconst1
run_starconst run_starconst1 : starconst
run_starconst :
	@./starconst
run_starconst1 :
	@./starconst \
	| awk '/cptrinc/ {p=0} p==1 {print} /CPTRINC/ {p=1}'

.PHONY: run_twopoint
RUNS += run_twopoint
run_twopoint : twopoint
	@./twopoint

.PHONY: run_pointy
RUNS += run_pointy
run_pointy : pointy
	@./pointy

.PHONY: run_printfpoint
RUNS += run_printfpoint
run_printfpoint : printfpoint
	@./printfpoint

.PHONY: run_coutpoint
RUNS += run_coutpoint
run_coutpoint : coutpoint
	@./coutpoint

.PHONY: run_cintpointer
RUNS += run_cintpointer
run_cintpointer : cintpointer
	@./cintpointer

.PHONY: run_ptr0
RUNS += run_ptr0
run_ptr0 : ptr0
	@./ptr0

.PHONY: run_ptr1
RUNS += run_ptr1
run_ptr1 : ptr1
	@./ptr1

.PHONY: run_ptr2
RUNS += run_ptr2
run_ptr2 : ptr2
	@./ptr2

.PHONY: run_ptr3a run_ptr3b
RUNS += run_ptr3a run_ptr3b
run_ptr3a : ptr3
	@./ptr3 \
	| awk '/pointer3a/ {p=0} p==1 {print} /Pointer3a/ {p=1}'
run_ptr3b : ptr3
	@./ptr3 \
	| awk '/pointer3b/ {p=0} p==1 {print} /Pointer3b/ {p=1}'

.PHONY: run_ptrdouble run_ptrdoubleinit
RUNS += run_ptrdouble run_ptrdoubleinit
run_ptrdouble : ptrdouble
	@./ptrdouble \
	| awk '/double/ {p=0} p==1 {print} /Double/ {p=1}'
run_ptrdoubleinit : ptrdouble
	@./ptrdouble \
	| awk '/init/ {p=0} p==1 {print} /Init/ {p=1}'

.PHONY: run_dynrect
RUNS += run_dynrect
run_dynrect : dynrectangle
	@./dynrectangle

.PHONY: run_any
RUNS += run_any
run_any : any
	@./any

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
