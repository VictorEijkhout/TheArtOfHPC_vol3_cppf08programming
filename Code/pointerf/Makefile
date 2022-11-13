# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
#### F90 programs for pointers
####
################################################################

PROGRAMS = basicp assignwrong assignright assignequals \
    arpointf interior \
    listfappend listfinsert listfalloc listfappendalloc listfinsertalloc \
    realp statusp allocptr

include ../Make.inc
LANGUAGE = F

RUNS =

RUNS += run_basicp
.PHONY: run_basicp
run_basicp : basicp
	@./basicp

RUNS += run_allocptr
.PHONY: run_allocptr
run_allocptr : allocptr
	@./allocptr

RUNS += run_statusp
.PHONY: run_statusp
run_statusp : statusp
	@./statusp

RUNS += run_interior
.PHONY: run_interior
run_interior : interior
	@./interior \
	| awk '/step 2/ {p=0} p==1 {print} /step 1/ {p=1}'

RUNS += run_assignright
.PHONY: run_assignright
run_assignright : assignright
	@./assignright

RUNS += run_assignequals
.PHONY: run_assignequals
run_assignequals : assignequals
	@./assignequals

.PHONY: run_realp check_realp
RUNS += run_realp
run_realp : realp
	@./realp
check_realp : realp
	@./realp > run.out && \
	cat run.out | awk '/1\.2/ { v = v+1 } /2\.4/ { v = v+1 } END {print v}' > chk.out && \
	n=` cat chk.out | awk '{print $$1}'` && \
	if [ $$n -ne 3 ] ; then \
	  echo "ERROR\n  Program realp failed: output=" ; \
	  cat run.out ; \
	else \
	  echo "Program realp ran successfully" ; \
	fi


.PHONY: run_arpointf
RUNS += run_arpointf
run_arpointf : arpointf
	@./arpointf

.PHONY: run_listf
RUNS += run_listf
listf_run : listf
	@./listf > run.out && \
	cat run.out | awk '/List/ { print $$3 } ' > chk.out && \
	n=` cat chk.out | awk '{print $$1}'` && \
	if [ $$n != "1,3,5," ] ; then \
	  echo "ERROR\n  Program listf failed: output=" ; \
	  cat run.out ; \
	else \
	  echo "Program listf ran successfully" ; \
	fi

.PHONY: run_listappend
RUNS += run_listappend
run_listappend : listfappendalloc
	@./listfappendalloc

.PHONY: run_listinsert
RUNS += run_listinsert
run_listinsert : listfinsert
	@./listfinsert

.PHONY: run_listalloc
run_listalloc: listfinsertalloc
	@./listfinsertalloc

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
