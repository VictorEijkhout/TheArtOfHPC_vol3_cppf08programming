# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2020 Victor Eijkhout
####
#### guide/Makefile : makefile for public version of the textbook
####
################################################################

.PHONY: info
info ::

info ::
	@echo "make all : code snippets, book"
.PHONY: all
all : snippets
	make manual book FILE=${FILE}

FILE = EijkhoutIntroSciProgramming
.PHONY: onepass format book manual pdf
info ::
	@echo "make onepass/format book [FILE=(default: ${FILE})]"
format onepass :
	@mkdir -p frames
	@TEXINPUTS=chapters:macros:snippets.code:graphics:${TEXINPUTS} \
	  pdflatex --shell-escape ${FILE}
book :
	@echo "Formatting as student book"
	@mkdir -p exercises
	@( cd macros && cp q.tex qa.tex )
	make pdf FILE=${FILE}
pdf :
	make snippets
	make onepass FILE=${FILE}
	make extract_exercises extract_slides
	makeindex ${FILE}
	make onepass FILE=${FILE}

##
## code snippets and exercise frames and whatnot
##
include ../makefiles/Make.snippets


##
## cleaning
##
include ../makefiles/Make.clean

clean ::
	@/bin/rm -f exercises/*
	@/bin/rm -f chapters/*~

clean :: local_clean
	@/bin/rm -rf chapters/*~
total_clean :: clean
	@/bin/rm -rf answers/* exercises/* frames/* snippets.code/* 
