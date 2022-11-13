!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** interfunc.F90 : a function for which we have an interface in Interface.F90
!***
!****************************************************************

!!codesnippet interfunc
function f(x,y)
  implicit none
  real*8 :: f
  real*8,intent(in) :: x,y
!!codesnippet end

  f = x+y
  return
end function f
