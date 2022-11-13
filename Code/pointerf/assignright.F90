!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** assignright.F90 : pointer copying done right
!***
!****************************************************************


Program AssignPointer

  implicit none

  !!codesnippet passignright
  real,target :: x
  real,pointer :: p1,p2

  x = 1.2
  p1 => x
  p2 => p1
  print *,p2
  !!codesnippet end

End Program AssignPointer

