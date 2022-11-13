# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++11 and Fortran2003
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
#### Examples of basic C++ constructs
####
################################################################

PROGRAMS = null hello return cin version onethird \
    name trunc ed eps equals point3 cindo root c2f f2c \
    cast size intshortlong intprec int123 io shadowtrue shadowfalse \
    ref modulo switch string \
    if logicop pretest whiledo dowhile ifinit bitor \
    setbyref arraypass \
    class template

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

RUNS =

RUNS += run_hello
.PHONY: run_hello
run_hello : hello
	@./hello

RUNS += run_version
.PHONY: run_version
run_version : version
	@./version

RUNS += run_onethird
.PHONY: run_onethird
run_onethird : onethird
	@./onethird

RUNS += run_truncf2i run_truncd2f
.PHONY: run_truncf2i run_truncd2f
run_truncf2i : trunc
	@( echo 2 && echo 3 && echo 3 ) \
	| ./trunc \
	| awk '/f2i/ {p=0} p==1 {print} /F2I/ {p=1}'
run_truncd2f : trunc
	@( echo 2 && echo 3 && echo 3 ) \
	| ./trunc \
	| awk '/d2f/ {p=0} p==1 {print} /D2F/ {p=1}'

RUNS += run_cin
.PHONY: run_cin
run_cin : cin
	( echo Victor ; echo 18 ) \
	 | ./cin
	( echo "Victor Eijkhout" ; echo 21 ) \
	 | ./cin

RUNS += run_return
.PHONY: run_return
run_return : return
	-./return ; \
	if [ $$? -ne 0 ] ; then \
	    echo "Program failed" ; \
	fi

RUNS += run_ed
.PHONY: run_ed
run_ed : ed
	@./ed

RUNS += run_whiledo
.PHONY: run_whiledo
run_whiledo : whiledo
	@( echo -3 ; echo 0 ; echo 2 ) | ./whiledo

RUNS += run_dowhile
.PHONY: run_dowhile
run_dowhile : dowhile
	@( echo -3 ; echo 0 ; echo 2 ) | ./dowhile

RUNS += run_point3
.PHONY: run_point3
run_point3 : point3
	@./point3

RUNS += run_equals
.PHONY: run_equals
run_equals : equals
	@for i in `seq 1 10` ; do \
	    echo $$i | ./equals \
	    ; \
	done

RUNS += run_eps
.PHONY: run_eps
run_eps : eps
	for e in .1 .01 .001 .0001 .00001 .000001 .0000001 .00000001 ; do \
	  echo $$e | eps ; echo ; done

RUNS += run_switch
.PHONY: run_switch
run_switch : switch
	for v in 1 2 3 4 5 ; do \
	  echo $$v | ./switch ; \
	done

RUNS += run_pretest
.PHONY: run_pretest
run_pretest : pretest
	@./pretest

RUNS += run_ref
.PHONY: run_ref
run_ref : ref
	@./ref

RUNS += run_bitor
.PHONY: run_bitor
run_bitor : bitor
	@./bitor

RUNS += run_setbyref
.PHONY: run_setbyref
run_setbyref : setbyref
	@./setbyref

RUNS += run_shadowtrue run_shadowfalse
.PHONY: run_shadowtrue run_shadowfalse
run_shadowtrue : shadowtrue
	@./shadowtrue | \
	  awk '/true/ {p=0} p==1 {print} /True/ {p=1}'
run_shadowfalse : shadowfalse
	@./shadowfalse | \
	  awk '/false/ {p=0} p==1 {print} /False/ {p=1}'

RUNS += run_if
.PHONY: run_if
run_if : if
	@for i in 50 150 ; do \
	    echo "... with $$i as input ...." \
	     && echo $$i | ./if \
	; done

RUNS += run_ifinit
.PHONY: run_ifinit
run_ifinit : ifinit
	for c in d b a z ; do \
	   echo $$c | ./ifinit ; \
	done

RUNS += run_int123
.PHONY: run_int123
run_int123 : int123
	@echo 0.1 | ./int123

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
