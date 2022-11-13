# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2021 Victor Eijkhout
####
################################################################

PROGRAMS = query arraypass1d arraypass2d jordan lapack multi \
    init mult norm normij section shape where printarray returnarray \
    forallshift quicksort

LANGUAGE = F
include ../Make.inc

RUNS =

RUNS += run_sectionassign
.PHONY: run_sectionassign sectionassign
run_sectionassign : section
	@./section \
	| awk ' /sectionassign/ { p=0 } p==1 {print} /SectionAssign/ { p=1 }'

RUNS += run_fsection2
.PHONY: run_fsection2 fsection2
fsection2 :: section
run_fsection2 :
	@./section \
	| awk ' /fsection2/ { p=0 } p==1 {print} /Fsection2/ { p=1 }'

RUNS += run_sectionmg
.PHONY: run_sectionmg sectionmg
run_sectionmg : section
	@./section \
	| awk ' /sectionmg/ { p=0 } p==1 {print} /SectionMg/ { p=1 }'

RUNS += run_printarray
.PHONY: run_printarray
run_printarray :: printarray
	@./printarray

RUNS += run_arraypass1d
.PHONY: run_arraypass1d
run_arraypass1d :: arraypass1d
	@./arraypass1d

RUNS += run_query
.PHONY: run_query
run_query :: query
	@./query \
	| awk '/q/ {p=0} p==1 {print} /Q/ {p=1}'

RUNS += run_lubound
.PHONY: run_lubound
run_lubound :: query
	@./query \
	| awk '/lu/ {p=0} p==1 {print} /LU/ {p=1}'

RUNS += run_multi
.PHONY: run_multi
run_multi :: multi
	@./multi

RUNS += run_forallf run_forallb
.PHONY: run_forallf run_forallb
run_forallf run_forallb : forallshift
run_forallf :
	@./forallshift \
	| awk '/ff/ {p=0} p==1 {print} /FF/ {p=1}'
run_forallb :
	@./forallshift \
	| awk '/bb/ {p=0} p==1 {print} /BB/ {p=1}'

RUNS += run_norm
.PHONY: run_norm
run_norm :: norm
	@ (for i in `seq 1 49` ; do echo $$i ; done ) | ./norm

RUNS += run_rowcolsum
.PHONY: run_rowcolsum
run_rowcolsum :: normij
	@./normij

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
