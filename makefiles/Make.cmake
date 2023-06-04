# -*- makefile -*-
################################################################
####
#### This makefile is part of the course
#### Introduction to Scientific Programming in C++ and Fortran
#### by Victor Eijkhout (eijkhout@tacc.utexas.edu)
#### copyright 2017-2023 Victor Eijkhout
####
#### Make.cmake : experimental cmake stuff
####
################################################################

info ::
	@echo && echo "================ Cmake rules:"
	@echo "make cmake PROGRAM=... : make program from this directory"
	@echo "make cmake_all : make all programs in this directory"
	@echo "    using builddir=./build, installdir=./exe"
	@echo "    [ PROGRAMS= ( default: ${PROGRAMS} ) ]"
.PHONY: cmake cmake_all
cmake :
	@codedir=`pwd` && codedir=$${codedir##*code/} \
	 && echo "Start cmake in: $$codedir" \
	 && rm -f CMakeLists.txt && cp ../CMakeLists.single.txt ./CMakeLists.txt \
	 && installdir=`pwd`/exe && builddir=`pwd`/build \
	 && rm -rf $$installdir && mkdir -p $$installdir \
	 && rm -rf $$builddir && mkdir -p $$builddir \
	 && if [ -z "${PROGRAM}" ] ; then \
	        echo "Variable PROGRAM not set" && exit 1 ; fi \
	 && cd .. && pwd \
	 && echo " .. cmake configure in: `pwd`" \
	 && echo " .. to prefix  : $$installdir" \
	 && echo " .. using build: $$builddir" \
	 && cmdline="cmake \
	        -S $$codedir -B $$builddir \
	        -D CMAKE_INSTALL_PREFIX=$$installdir \
	        -D CMAKE_VERBOSE_MAKEFILE=ON \
	        -D CMAKE_CXX_STANDARD=${CPPSTANDARD} \
	        -D PROGRAM_NAME=${PROGRAM}" \
	 && echo " .. executing: $$cmdline" && eval $$cmdline \
	 && echo && echo " .. cmaking done" && echo \
	 && ( cd $$builddir && make V=1 && make install ) \
	 && echo && echo "installation:" && ls $$installdir && echo
cmake_all :
	@codedir=`pwd` && codedir=$${codedir##*code/} \
	 && echo "Start cmake in: $$codedir" \
	 && rm -f CMakeLists.txt && cp ../CMakeLists.all.txt ./CMakeLists.txt \
	 && installdir=`pwd`/exe && builddir=`pwd`/build \
	 && rm -rf $$installdir && mkdir -p $$installdir \
	 && rm -rf $$builddir && mkdir -p $$builddir \
	 && if [ -z "${PROGRAMS}" ] ; then \
	        echo "Variable PROGRAMS not set" && exit 1 ; fi \
	     && programs="${PROGRAMS}" \
	     && programs=$$( echo $$programs | tr ' ' ';' ) \
	 && cd .. && pwd \
	 && echo " .. cmake configure in: `pwd`" \
	 && echo " .. to prefix  : $$installdir" \
	 && echo " .. using build: $$builddir" \
	 && cmake \
	        -S $$codedir -B $$builddir \
	        -D CMAKE_INSTALL_PREFIX=$$installdir \
	        -D CMAKE_VERBOSE_MAKEFILE=ON \
	        -D programs=$$programs \
	 && echo && echo " .. cmaking done" && echo \
	 && ( cd $$builddir && make V=1 && make install ) \
	 && echo && echo "installation:" && ls $$installdir && echo

clean ::
	@rm -rf build exe CMake*
