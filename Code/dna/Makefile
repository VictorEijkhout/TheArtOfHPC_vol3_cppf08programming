# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2018-2023 Victor Eijkhout
####
#### makefile for dna sequencing examples and exercises
####
#### https://www.reddit.com/r/SNPedia/comments/11uvaar/how_to_gain_access_snpedia/
#### https://bots.snpedia.com/api.php?action=help&modules=query
#### https://bots.snpedia.com/api.php?action=query&list=categorymembers&cmtitle=Category:Is_a_snp&cmlimit=max&format=json
####
################################################################

PROGRAMS = bases virus quality match boyer \
    snp
MODULES = json

LANGUAGE = CXX
include ../Make.inc
INCLUDES = -I${LMOD_JSON_INC}

RUNS = 

RUNS += run_bases
run_bases : bases
	@./bases

RUNS += run_boyer
run_boyer : boyer
	@./boyer

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
