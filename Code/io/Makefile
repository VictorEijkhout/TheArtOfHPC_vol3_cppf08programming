# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++11 and Fortran2003
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2022 Victor Eijkhout
####
#### Examples of basic C++ constructs
####
################################################################

PROGRAMS = io16 iof fio fiobin fix align \
    cin cinfloat cunformat width formatpad formatleft format16 formatfloat \
    quasifix quickinput quickcount fmtlib bits
WRONGS = \
    stdformat

LANGUAGE = CXX
include ../Make.inc
CPPSTANDARD = 20
INCLUDES = -I${TACC_FMTLIB_INC}
EXTRALIBS = -L${TACC_FMTLIB_LIB} -lfmt
MODULES = fmtlib

RUNS = 

##
## whole bunch of i/o runs
##

RUNS += run_cin run_cinin run_cinfloat
run_cin : cin
	echo "Victor" | ./cin
run_cinin : cin
	echo "Victor Eijkhout" | ./cin
run_cinfloat : cinfloat
	for n in \
	    1.5  1.6  1.67  1.67e5  2.5.6  \
	    ; do \
	        echo $$n | ./cinfloat \
	; done

RUNS += run_cunformat
run_cunformat : cunformat
	@./cunformat

RUNS += run_width
run_width : width
	@./width

RUNS += run_fix
run_fix : fix
	@./fix

RUNS += run_bits
run_bits : bits
	@./bits

RUNS += run_align
run_align : align
	@./align

RUNS += run_fio
run_fio : fio
	echo 24 | ./fio \
	 && cat fio_example.out

RUNS += run_fiobin
run_fiobin : fiobin
	echo 25 | ./fiobin ; \
	  od fio_binary.out

RUNS += run_formatpad
run_formatpad : formatpad
	@./formatpad

RUNS += run_formatleft
run_formatleft : formatleft
	@./formatleft

RUNS += run_formatfloat
run_formatfloat : formatfloat
	@./formatfloat

RUNS += run_format16
run_format16 : format16
	@./format16

RUNS += run_block16
run_block16 : io16
	@./io16 | awk '/Block16:/ {p=1} /block16:/ {p=0} p==1 {print}'

RUNS += run_quickcount
run_quickcount : quickcount
	@./quickcount

RUNS += run_quickinput
run_quickinput : quickinput
	@./quickinput

RUNS += run_quasifix
run_quasifix : quasifix
	@./quasifix

RUNS += run_iofsci
run_iofsci : iof
	@./iof \
	 | awk '/iofsci/ {p=0} p==1 {print} /IOFSCI/ {p=1}'

FMTRUNS = run_fmtbasic run_fmtwidth run_fmtleftpad run_fmtbase run_fmtstream 
RUNS += ${FMTRUNS}
${FMTRUNS} :: fmtlib
run_fmtbasic  ::
	@./fmtlib \
	| awk '/basic/ {p=0} p==1 {print} /Basic/ {p=1}'
run_fmtwidth ::
	@./fmtlib \
	| awk '/width/ {p=0} p==1 {print} /Width/ {p=1}'
run_fmtleftpad ::
	@./fmtlib \
	| awk '/leftpad/ {p=0} p==1 {print} /Leftpad/ {p=1}'
run_fmtbase ::
	@./fmtlib \
	| awk '/base/ {p=0} p==1 {print} /Base/ {p=1}'
run_fmtstream ::
	@./fmtlib \
	| awk '/stream/ {p=0} p==1 {print} /Stream/ {p=1}'
.PHONY: ${RUNS}

include ../../makefiles/Make.cmake
include ../../makefiles/Make.clean
