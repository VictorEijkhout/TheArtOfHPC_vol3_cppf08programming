# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017/8 Victor Eijkhout
####
#### makefile for PageRank examples
####
################################################################

PROGRAMS = web web2 dense adjacent1 adjacent2

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 14

RUNS =

RUNS += run_pdfsetup
.PHONY: run_pdfsetup
run_pdfsetup : web
	@./web \
	| awk '/done probability/ {p=0} p==1 {print} /Set up a probability/ {p=1}'

RUNS += run_seo
run_seo : web
	@./web \
	| awk '/seoseo/ {p=0} p==1 {print} /SEOSEO/ {p=1}'

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
