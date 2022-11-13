!****************************************************************
!****
!**** This file belongs with the course
!**** Introduction to Scientific Programming in C++/Fortran2003
!**** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
!****
!**** pointmain.F90 : make a Point class just for exercise
!****
!****************************************************************

Program PointTest
  !!codesnippet pointmainex
  use pointmod
  implicit none
  type(Point) :: p1,p2
  real(8) :: p1x,p1y,p2x,p2y
  read *,p1x,p1y,p2x,p2y
  p1 = point(p1x,p1y)
  p2 = point(p2x,p2y)
  print *,"Distance:",distance(p1,p2)
  !!codesnippet end

End Program PointTest

