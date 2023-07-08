# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
####
################################################################

PROGRAMS = binary linksimple linkshared linkunique traverse \
    singlesource1 singlesource2 dijkstra1 dijkstra2 \
    queuelevel queuedijkstra graphmvp graphmvpdijkstra
PROGRAM = linksimple

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 17

RUNS =

.PHONY: run_link
RUNS += run_link
run_link : link
	@./link

.PHONY: run_linkunique
RUNS += run_linkunique
run_linkunique : linkunique
	@./linkunique

.PHONY: run_linkshared
RUNS += run_linkshared
run_linkshared : linkshared
	@./linkshared

.PHONY: run_append
RUNS += run_append
run_append : linksimple
	@./linksimple \
	| awk '/append/ {p=0} p==1 {print} /Append/ {p=1}'

.PHONY: run_insert
RUNS += run_insert
run_insert : linksimple
	@./linksimple \
	| awk '/insert/ {p=0} p==1 {print} /Insert/ {p=1}'

.PHONY: run_traverse
RUNS += run_traverse
run_traverse : traverse
	@./traverse

.PHONY: run_dijkstra1
RUNS += run_dijkstra1
run_dijkstra1 : dijkstra1
	@./dijkstra1
dijkstra1.o dijkstra2.o : levelset.cpp

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
