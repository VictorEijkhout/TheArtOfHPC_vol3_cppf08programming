!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** assignwrong.F90 : pointer copying done wrong
!***
!*** THIS CODE IS WRONG: IT ILLUSTRATES A COMMON CODING ERROR !!!!
!***
!****************************************************************


Program AssignPointer

  implicit none

  !!codesnippet passignwrong
  real,target :: x
  real,pointer :: p1,p2

  x = 1.2
  p1 => x
  p2 = p1
  print *,p2
  !!codesnippet end

End Program AssignPointer

