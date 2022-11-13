!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** vartype.F90 : include file for the namedvar type
!***
!****************************************************************

  !!codesnippet fvarstackvar
  type namedvar
     character :: id
     character(len=20) :: expression
     integer :: value
  end type namedvar
  !!codesnippet end
