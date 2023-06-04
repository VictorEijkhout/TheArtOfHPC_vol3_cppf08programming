# -*- makefile -*-
################################################################
################################################################
####
#### This Makefile belong with the sources
#### for Introduction to High-Performance Scientific Computing
#### by Victor Eijkhout
#### copyright 2010-2021
####
#### makefile for code/compile
####
################################################################
################################################################

info ::

PROGRAMS = hello

LANGUAGE = CXX
include ../Make.inc

oneprogram : fooprog.o foosub.o
	${LINKER} -g -O2 -o $@ $^

##
## code stripping
##
SOURCES = fooprog.c foosub.c rotate.c hello.c
info ::
	@echo "make strip_sources : remove header"
.PHONY: strip_sources
strip_sources :
	for s in ${SOURCES} ; do \
	    cat $$s | awk 'p==1 && !/snippet/ {print} NF==0 {p=1}' > $$s.stripped.out \
	    ; done
total_clean ::
	@rm -f *.stripped_out

## include ../../makefiles/Make.public

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
clean ::
	@rm -f *.optrpt *.annot

.PHONY: example_clean
info ::
	@echo "make example_clean : remove local binaries"
example_clean ::
	@rm -f ${PROGRAMS} ${LIBS}
clean :: example_clean
	@rm -rf libs
