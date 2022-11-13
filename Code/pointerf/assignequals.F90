!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** assignequals.F90 : pointer copying subtlety
!***
!****************************************************************


Program AssignPointer

  implicit none

  !!codesnippet passignequals
  real,target :: x,y
  real,pointer :: p1,p2

  x = 1.2
  p1 => x
  p2 => y
  p2 = p1 ! same as y=x
  print *,p2 ! same as print y
  !!codesnippet end

End Program AssignPointer

