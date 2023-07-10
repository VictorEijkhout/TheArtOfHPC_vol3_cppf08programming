# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2023 Victor Eijkhout
####
#### Make.inc : general makefile rules for compiling the exercises
####
################################################################

.PHONY: info
info ::
	@echo && echo "================ Compilation rules"
	@echo "make language : print language"
.PHONY: language
language :
	@echo "${LANGUAGE}"

info ::
	@echo "make <program> where program=${PROGRAMS}"
	@echo "     [COMPILER=... (default: ${COMPILER})]"
	@echo "     [OPTLEVEL=... (default: ${OPTLEVEL})]"
	@echo "     [OPTIONS=... ]"
	@if [ ! -z "${WRONGS}" ] ; then \
	    echo "troublesome sources: ${WRONGS}" ; fi
	@if [ ! -z "${INPROGRESS}" ] ; then \
	    echo "work in progress: ${INPROGRESS}" ; fi
	@make modules
.PHONY: modules listmodules
listmodules :
	@echo "${MODULES}"
modules :
	@needs="" \
	 && for m in ${MODULES} ; do \
	      mdir=TACC_$${m}_DIR \
	       && mdir=$$( env | grep -i $${mdir} | cut -d = -f 2 ) \
	       && if [ -z "$${mdir}" ] ; then \
	  	    needs="$$needs $$m" \
	           ; \
	          fi \
	       ; \
	     done \
	     && if [ ! -z $$needs ] ; then \
	          echo "Please load modules:$$needs" \
	           && echo  \
	           && exit 1 \
	           ;  \
	        fi 

WARNING_OPTIONS =
# -Wall -Wextra -Wno-unused-variable
# -Wconversion
ifeq "${TACC_FAMILY_COMPILER}" "intel"
  # --gcc-toolchain=/opt/apps/gcc/12.2.0
  C_COMPILER = ${CC}
  CXX_COMPILER = ${CXX} 
  F_COMPILER = ${FC}
  F_OPTIONS = -stand f08
  OMP_OPTIONS = -qopenmp
else ifeq "${TACC_FAMILY_COMPILER}" "oneapi"
  C_COMPILER = /bin/false
  CXX_COMPILER = icpx
  F_COMPILER = ifx
  F_OPTIONS = -stand f08
  OMP_OPTIONS = -qopenmp
else ifeq "${TACC_FAMILY_COMPILER}" "gcc"
  C_COMPILER = gcc
  CXX_COMPILER = g++
  F_COMPILER = gfortran
  F_OPTIONS = -std=f2008
  OMP_OPTIONS = -fopenmp
else ifeq "${TACC_FAMILY_COMPILER}" "clang"
  C_COMPILER = clang-mp-16
  CXX_COMPILER = clang++-mp-16
  F_COMPILER = gfortran
endif
J_COMPILER = julia
COMPILER = ${${LANGUAGE}_COMPILER}
LINKER   = ${COMPILER}
OPTLEVEL = 2

info ::
	@echo "     [ CPPSTANDARD=11/14/17 (default=${CPPSTANDARD}) ]"
	@echo "     [ INCLUDES=... ]"
	@echo "     [ EXTRALIBS=... ]"
# redefine standards after including this file! 
ifdef CPPSTANDARD
else
  CPPSTANDARD = 17
endif
ifdef CSTANDARD
else
  CSTANDARD = 99
endif

.SECONDEXPANSION:
${EXERCISES} ${PROGRAMS} ${WRONGS} ${INPROGRESS} : $$@.o
	@\
	if [ ! -z "${RPATH}" ] ; then rpath="-Wl,-rpath,${RPATH}" ; fi \
	 && cmdline="${LINKER} \
	    -g -O${OPTLEVEL} ${OPTIONS} ${OMP_OPTIONS} \
	    -o $@ $^ \
	    $${rpath} ${EXTRALIBS} \
	    " \
	 && if [ ! -z "${ECHO}" ] ; then \
	        echo "Linking: $$cmdline" ; fi \
	 && eval $$cmdline

.SUFFIXES:
.SUFFIXES: c cc cpp cxx F90 f90
%.o : %.cpp modules
	@cmdline="${CXX_COMPILER} -g -c -std=c++${CPPSTANDARD} ${CPP_OPTIONS} \
	    -O${OPTLEVEL} ${INCLUDES} ${OPTIONS} ${WARNING_OPTIONS} \
	    -o $@ $*.cpp" \
	 && if [ ! -z "${ECHO}" ] ; then \
	        echo "Compiling: $$cmdline" ; fi \
	 && eval $$cmdline
%.o : %.cxx modules
	@cmdline="${CXX_COMPILER} -g -c -std=c++${CPPSTANDARD} ${CXX_OPTIONS} \
	    -O${OPTLEVEL} ${INCLUDES} ${OPTIONS} ${WARNING_OPTIONS} \
	    -o $@ $*.cxx" \
	 && if [ ! -z "${ECHO}" ] ; then \
	        echo "Compiling: $$cmdline" ; fi \
	 && eval $$cmdline
%.o : %.F90
	@cmdline="${F_COMPILER} -g ${F_OPTIONS} \
	    -O${OPTLEVEL} ${INCLUDES} ${OPTIONS} \
	    -c $*.F90 -o $@" \
	 && if [ ! -z "${ECHO}" ] ; then \
	        echo "Compiling: $$cmdline" ; fi \
	 && eval $$cmdline
%.o : %.f90
	@${F_COMPILER} -g ${F_OPTIONS} \
	    -O${OPTLEVEL} ${INCLUDES} ${OPTIONS} \
	    -c $*.f90 -o $@
%.mod : %.F90
	@cmdline="${F_COMPILER} -g ${F_OPTIONS} \
	    -O${OPTLEVEL} ${INCLUDES} ${OPTIONS} \
	    -c $*.F90 " \
	 && if [ ! -z "${ECHO}" ] ; then \
	        echo "Compiling: $$cmdline" ; fi \
	 && eval $$cmdline
%.o : %.c
	@cmdline="${C_COMPILER} -g -c -std=c${CSTANDARD} ${C_OPTIONS} \
	    -O${OPTLEVEL} ${INCLUDES} ${OPTIONS} \
	    -o $@ $*.c" \
	 && if [ ! -z "${ECHO}" ] ; then \
	        echo "Compiling: $$cmdline" ; fi \
	 && eval $$cmdline

info ::
	@echo "make exercise PROGRAM=..."
.PHONY: exercise
exercise :
	@if [ -z "${PROGRAM}" ] ; then \
	  echo "Usage: make exercise PROGRAM=..." ; \
	  exit 1; \
	fi
	@echo "writing ${PROGRAM}_exercise.cpp"
	@cat ${PROGRAM}.cpp \
	| awk ' BEGIN {p=1} \
	        /answersnippet/ && $$2!="end" {p=0} \
	        p==1 && !/codesnippet/ {print} \
	        /answersnippet end/ {print "/* MISSING CODE HERE */" ; p=1} \
	      ' \
	>${PROGRAM}_exercise.cpp

info ::
	@echo "make apps : compile everything"
.PHONY: apps
apps :
	@for a in ${PROGRAMS} ${EXERCISES} ; do \
	    echo "compiling: $$a" \
	     && make --no-print-directory $$a \
	    ; \
	done

info ::
	@echo && echo "================ Output and regression "
	@echo "make runs : compile and run everything"
	@echo "make runouts : compile and run everything and generate output file"
.PHONY: runs runouts
runs :
	@for r in ${RUNS} ; do \
	    echo "---------------- Test run: $$r ----------------" \
	     && runname=$${r##run_} \
	     && make --no-print-directory $$r \
	           EXTRALIBS="${EXTRALIBS}" OPTIONS="${OPTIONS}" OPTLEVEL=${OPTLEVEL} \
	           ECHO=${ECHO} \
	 ; done
runouts :
	@for r in ${RUNS} ; do \
	    echo "---------------- Test run: $$r ----------------" \
	     && runname=$${r##run_} \
	     && make --no-print-directory $$r \
	           EXTRALIBS=${EXTRALIBS} OPTIONS=${OPTIONS} OPTLEVEL=${OPTLEVEL} \
	        2>&1 | tee $$runname.runout \
	     && git add $$runname.runout \
	 ; done

#
# clean rules
#
MAKEFILESDIR = ../../makefiles
include ${MAKEFILESDIR}/Make.clean
total_clean ::
	@rm -f *.runout

info ::
	@echo "make regressioncompile regressionrun [ ECHO= (nonzero for trace output) ]"
.PHONY: regressionrun regressioncompile 
## NOTE should we start by zero'ing regression.out?
regressioncompile : clean
	@count=0 \
	 && if [ ! -z "${PROGRAMS}" -a ! "${LANGUAGE}" = "J" ] ; then \
	      for p in ${PROGRAMS} ; do \
	          if [ ! -z "${ECHO}" ] ; then echo "Compiling $$p" ; fi \
	           && ( \
	              echo "Compiling $$p" \
	               && make --no-print-directory ECHO=${ECHO} $$p \
	              ) 2>&1 >>regression.out \
	           && count=$$(( count+1 )) \
	      ; done \
	       && if [ $$count -ne `cat regression.out | wc -l` ] ; then \
	              echo "Errors in regression:"  && cat regression.out \
	          ; else \
	              echo "Programs successfully compiled: ${PROGRAMS}" \
	          ; fi \
	    ; fi 
clean ::
	@rm -f regression.out
regressionrun : regressioncompile
	if [ ! -z "${RUNS}" ] ; then \
	    make ${RUNS} ; \
	fi 

info ::
	@if [ ! -z "${RUNS}" ] ; then \
	  echo "Available regression runs:" ; echo "  ${RUNS}" ; \
	fi

info ::
	@echo "================ other stuff"
	@echo "make skeleton SKEL=..."
.PHONY : skeleton
SKEL =
skeleton :
	@if [ -z "${SKEL}" ] ; then \
	    echo "Usage: make skeleton SKEL=..." && exit 1 ; fi
	@if [ "${LANGUAGE}" = "F" ] ; then \
	    make --no-print-directory skeletonfile SKEL=${SKEL} EXT=F90; \
	else \
	    make --no-print-directory skeletonfile SKEL=${SKEL} EXT=cpp ; \
	fi
skeletonfile :
	@skel=${SKEL} && skel=$${skel%%.${EXT}} \
	 && echo "copying skeleton: $${skel}.${EXT}" \
	 && cat $${skel}.${EXT} \
	    | awk 'BEGIN { p=1 } \
	            /answersnippet/ && !/end/ { p=0 } \
	           !/codesnippet/ && p==1    { print } \
	           /answersnippet end/       { p=1 } ' \
	    > ../../skeletons/$${skel}.${EXT} \
	 && git add ../../skeletons/$${skel}.${EXT}

info ::
	@echo "calltree PROGRAM=..."
.PHONY: calltree
calltree :
	@perf record -g -- ./${PROGRAM}
	@perf script | c++filt | python3 ${HOME}/bin/gprof2dot/gprof2dot.py -f perf | dot -Tpng -o ${PROGRAM}.png

include ../../makefiles/Make.snippets

clean :: local_clean
	@/bin/rm -f ${PROGRAMS} ${WRONGS} ${EXAMPLES} ${INPROGRESS}
local_clean ::
