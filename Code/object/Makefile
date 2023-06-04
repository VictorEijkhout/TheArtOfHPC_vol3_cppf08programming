# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++11 and Fortran2003
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
####
#### Examples of C++ objects
####
################################################################

info ::

PROGRAMS = functionality \
    accessref compare default destructor exceptdestruct destructexercise \
    copyscalar copyvector rvaluecopy \
    hasvector densevec funcvec memberinit \
    stream this unit static mutable \
    virtual functor polymorph1 polymorph2
WRONGS =  constructparen
EXAMPLES = rv

densevec.o funcvec.o : virtualvec.h

include ../Make.inc
CPPSTANDARD=17
LANGUAGE = CXX
OPTIONS = -fno-elide-constructors

.PHONY: ${RUNS}
RUNS =

RUNS += run_defaultno
run_defaultno : default
	@./default

RUNS += run_functionality
run_functionality : functionality
	@./functionality

RUNS += run_copyscalar
run_copyscalar : copyscalar
	@./copyscalar

RUNS += run_copyvector
run_copyvector : copyvector
	@./copyvector

RUNS += run_destructor
run_destructor : destructor
	@./destructor

RUNS += run_destructexercise
run_destructexercise : destructexercise
	@./destructexercise

RUNS += run_exceptobj run_exceptdestruct
run_exceptdestruct run_exceptobj : exceptdestruct
	@./exceptdestruct

RUNS += run_accessref
run_accessref : accessref
	@./accessref

RUNS += run_densevec
run_densevec : densevec
	@./densevec

RUNS += run_funcvec
run_funcvec : funcvec
	@./funcvec

RUNS += run_stream
run_stream : stream
	@./stream

RUNS += run_this
run_this : this
	@./this \
	| awk '/this/ {p=0} p==1 {print} /This/ {p=1}'

RUNS += run_virtual
run_virtual : virtual
	@./virtual

RUNS += run_unit
run_unit : unit
	@./unit

RUNS += run_static
run_static : static
	@./static

RUNS += run_functor
run_functor : functor
	@./functor \
	| awk '/one/ {p=0} p==1 {print} /One/ {p=1}'
RUNS += run_functor2
run_functor2 : functor
	@./functor \
	| awk '/two/ {p=0} p==1 {print} /Two/ {p=1}'

RUNS += run_spaceship
run_spaceship : 
	@make --no-print-directory CPPSTANDARD=20 compare \
	 && ./compare

RUNS += run_polymorph1
run_polymorph1 : polymorph1
	@./polymorph1

RUNS += run_polymorph2
run_polymorph2 : polymorph2
	@./polymorph2

RUNS += run_mutable
run_mutable : mutable
	@./mutable

.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
