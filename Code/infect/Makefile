# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2016-2023
####
#### Makefile for infectuous disease simulation
####
################################################################

.PHONY: info
info ::

PROGRAMS = \
    person interaction pandemic mutate

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17
INCLUDES = -I${TACC_CXXOPTS_INC}
MODULES = cxxopts

OBJS=$(patsubs %,%.o,${PROGRAMS})
${OBJS} infect_lib.o : infect_lib.h
${PROGRAMS} : infect_lib.o
clean ::
	@rm -f infect_lib.o

info ::
	@echo "make ${RUNS}"
	@echo "  supported environment variables:"
	@echo "  POPULATION= (default ${POPULATION})"
	@echo "  CONTACT= (contacts per day)"
	@echo "  PROBABILITY= ( default ${PROBABILITY})"
	@echo "  DEBUG=1 (for debug output)"
POPULATION = 10000
VACCINATION = 1
PROBABILITY = 50
DEBUG =
RANGE = 10
EXTRA =
CONTACT = 6

RUNS += run_duration
info ::
	@echo "make run_duration [ POPULATION=... ] [ PROBABILITY=... ] [ ECHO=... ]"
run_duration : pandemic
	@for v in $$( seq 0 5 50  ) $$( seq 52 2 100 ) ; do \
	    cmd="./pandemic -n ${POPULATION} -i 3 -t 2 -p ${PROBABILITY} -v $${v}" \
	     && if [ "${ECHO}" = "1" ] ; then \
	            echo $$cmd ; fi \
	     && eval $$cmd | awk '/Population/ {print $$6 " : " $$14}' \
	 ; done
RUNS += run_peak
run_peak : pandemic
	@echo "Finding max runtime. Options: ${OPTIONS}"
	@echo "(prob %vax #days)"
	@for p in $$( seq 5 5 100 ) ; do \
	    make --no-print-directory run_duration PROBABILITY=$${p} ${OPTIONS} \
	    | awk -v p=$$p '\
	            BEGIN { run=0 } \
	            { if ($$3>run) { loc=$$1; run=$$3; } } \
	            END { print p " : " loc " : " run } \
	            ' \
	 ; done
##
## gprof profiling
##
RUNS += run_profile
run_profile : 
	@prog=pandemic \
	 && if [ "${TACC_FAMILY_COMPILER}" = "gcc" ] ; then \
	      profflag=pg ; else profflag=pg ; fi \
	 && echo "==== Rebuilding .." \
	 && rm -f $${prog} $${prog}.o infect_lib.o \
	 && make --no-print-directory $${prog} OPTIONS="-$${profflag}" ECHO=1 \
	 && echo "==== Running .." \
	 && cmdline="./$${prog} -n ${POPULATION} -i 3 -t 2 -p ${PROBABILITY} -v 50" \
	 && if [ "${ECHO}" = "1" ] ; then echo "Execute: $$cmdline" ; fi && eval $$cmdline \
	 && echo "==== Analysis .." \
	 && gprof $${prog} gmon.out > $${prog}.out \
	 && echo "See: $${prog}.out for gprof output"

run_mutate : mutate
	@for v in $$( seq 80 2 100 ) ; do ./mutate -v $$v ; done


include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
