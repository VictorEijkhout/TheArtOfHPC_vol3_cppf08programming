# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017 Victor Eijkhout
####
#### root makefile
####
################################################################

.PHONY: info
info ::
	@echo
	@echo "These are the available rules in this makefile:"
	@echo
	@echo "make book : format the textbook"
	@echo "make lectures : format the lecture slides"
	@echo

.PHONY: book
BOOKNAME = EijkhoutIntroSciProgramming
BOOKSRC = ispbook
book :
	@cd Book; make book

.PHONY: lectures
lectures :
	@cd Lectures

.PHONY: clean
clean :
	@/bin/rm -f *~
	@for d in Book ; do \
	    ( cd $$d ; make clean ) ; \
	done
