!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** e0.F90 : constants
!***
!****************************************************************

Program D0
  implicit none

  !!codesnippet f0const
  real(8) :: x,y,z
  x = 1.
  y = .1
  z = x+y
  print *,z
  x = 1.d0
  y = .1d0
  z = x+y
  print *,z
  !!codesnippet end

End Program D0
