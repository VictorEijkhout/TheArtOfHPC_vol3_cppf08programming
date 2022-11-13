# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
#### F90 programs for structures, types, classes
####
################################################################

PROGRAMS = contains module pointtype parampoint typemod \
    namedvar varhandling interchar interpret internum intermod interclass
LANGUAGE = F
include ../Make.inc


RUNS =

RUNS += run_pointtype
.PHONY: run_pointtype
run_pointtype : pointtype
	@./pointtype > run.out && \
	cat run.out | awk '/2\.5/ { v = v+1 } /3\.7/ { v = v+1 } END {print v}' > chk.out && \
	n=` cat chk.out | awk '{print $$1}'` && \
	if [ $$n -ne 2 ] ; then \
	  echo "ERROR\n  Program pointtype failed: output=" ; \
	  cat run.out ; \
	else \
	  echo "Program pointtype ran successfully" ; \
	fi

RUNS += run_typemod
.PHONY: run_typemod
run_typemod : typemod
	@./typemod

RUNS += run_namedvar
.PHONY: run_namedvar
run_namedvar : namedvar
	@./namedvar

##
## Interpreter exercises
##
RUNS += run_varhandling run_interchar \
     run_stackname run_stackop run_internum run_intermod run_interclass
.PHONY: run_varhandling run_interchar \
     run_stackname run_stackop run_internum run_intermod run_interclass

run_varhandling : varhandling
	@./varhandling

run_stackname : interpret
	@inputs="1 x 2 y 0" \
	 && echo "Inputs: $$inputs" \
	 && for c in $$inputs ; do echo $$c ; done \
	    | ./interpret
run_stackop : interpret
	@inputs="1 2 + z 0" \
	 && echo "Inputs: $$inputs" \
	 && for c in $$inputs ; do echo $$c ; done \
	    | ./interpret
run_stackfind : interpret
	@inputs="1 x 2 y x y + z 0" \
	 && echo "Inputs: $$inputs" \
	 && for c in $$inputs ; do echo $$c ; done \
	    | ./interpret
internum.o : interpretvn.F90 interpretsn.F90 interpretmn.F90
interpretmn.F90 : interpretm.F90
	@cat $< | grep -v "%id" | grep -v snippet \
	 | awk 'BEGIN { p=1 } /NOID/ {p=0} p==1 {print} /noid/ {p=1}' > $@
interpretsn.F90 : interprets.F90
	@cat $< | grep -v "%id" | grep -v snippet \
	 | awk 'BEGIN { p=1 } /NOID/ {p=0} p==1 {print} /noid/ {p=1}' > $@
interpretvn.F90 : interpretv.F90
	@cat $< | grep -v "%id" | grep -v snippet \
	 | awk 'BEGIN { p=1 } /NOID/ {p=0} p==1 {print} /noid/ {p=1}' > $@
clean ::
	@rm -f interpretvn.F90 interpretsn.F90 interpretmn.F90

run_internum : internum
	@inputs="4 5 6 0" \
	 && echo "Inputs: $$inputs" \
	 && for c in $$inputs ; do echo $$c ; done \
	    | ./internum
run_interchar : interchar
	@inputs="4 x 3 + 0" \
	 && echo "Inputs: $$inputs" \
	 && for c in $$inputs ; do echo $$c ; done \
	    | ./interchar
run_internumop : internum
	@inputs="4 5 6 + + 0" \
	 && echo "Inputs: $$inputs" \
	 && for c in $$inputs ; do echo $$c ; done \
	    | ./internum
run_intermod : intermod
	@for c in 5 x 6 y x y + z 0 ; do \
	    echo $$c \
	 ; done | ./intermod
run_interclass : interclass
	@inputs="5 x 6 y x y + z 0" \
	 && echo "Inputs: $$inputs" \
	 && for c in $$inputs ; do echo $$c ; done \
	    | ./interclass
interpret.o intermod.o : interpretv.F90 interpretc.F90 interprets.F90
intermod.o : interpretm.F90
interclass.o : interpretv.F90 interpretc.F90 interpretsc.F90 interpretmc.F90

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
