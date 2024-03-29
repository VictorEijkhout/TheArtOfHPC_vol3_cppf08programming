# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2023 Victor Eijkhout
####
#### code makefile
####
################################################################

.PHONY: info
info ::

####
#### Regression:
#### do regression in all subdirectories
####
.PHONY: regression
info ::
	@echo "make regression : compile everything"
	@echo "    [ LANGUAGE=... (default: ${LANGUAGE}) ]"
	@echo "    [ ECHO=... (nonzero for trace output) ]"
LANGUAGE = CXX
ECHO = 
regression :
	@for d in * ; do \
	  if [ -d $$d ] ; then \
	      ( \
	        cd $$d \
	         && if [ -f Makefile ] ; then \
	              if [ "${LANGUAGE}" = \
	                    $$( grep LANGUAGE Makefile | awk '{print $$3}' ) ] ; then \
	                echo "================" && echo "Regression in: $$d" \
	                 && make --no-print-directory regressioncompile ECHO=${ECHO} \
	              ; fi \
	            ; fi \
	      ) 2>&1 | tee -a regression.log \
	  ; fi \
	; done \
	&& echo && echo "see regression.log" && echo
clean ::
	@rm -f regression.log
.PHONY: runs
runs :
	@( \
	  for d in * ; do \
	    if [ -d "$${d}" ] ; then \
	        echo && echo "Regenerating all runs in $$d" \
	         && ( cd "$${d}" && make --no-print-directory runs ) \
	    ; fi \
	  ; done \
	 ) 2>&1 | tee runs.log
clean ::
	@rm -f runs.log

.PHONY: check
check :
	@for d in * ; do \
	  if [ -d $$d ] ; then \
	  ( cd $$d && \
	    if [ -f Makefile ] ; then \
	      echo "================" && echo "Checking in: $$d" ; \
	      make check ; \
	    fi ; \
	  ) ; \
	  fi ; \
	done

####
#### Clean up
####
.PHONY: clean
info ::
	@echo "make clean"
clean ::
	@/bin/rm -f *~ 
	@for d in * ; do \
	  if [ -d $$d ] ; then \
	  ( cd $$d && \
	    if [ -f Makefile ] ; then \
	      echo ".. cleaning in $$d" && \
	      make --no-print-directory clean ; \
	    fi \
	  ) ; \
	  fi ; \
	done
