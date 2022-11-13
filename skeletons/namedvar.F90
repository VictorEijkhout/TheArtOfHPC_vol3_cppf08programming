!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** namedvar.F90 : type with name field handling
!***
!****************************************************************

Program NamedVarType
  implicit none

  type namedvar
     character(len=20) :: id
     integer :: value
  end type namedvar
  type(namedvar) :: x,y,z,a

  x = namedvar("x", 1 )
  print *,x
  y = namedvar("y", 2 )
  print *,y
  z = varadd(x,y)
  print *,z
  a = varmult(z,x)
  print *,a

contains
  
end Program NamedVarType
