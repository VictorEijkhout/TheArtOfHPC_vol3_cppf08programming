!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** basic.F90 : pointer to real
!***
!****************************************************************


Program PointAtReal

  implicit none

  !!codesnippet pointsetprint
  real,target :: x
  real,pointer :: point_at_real

  x = 1.2
  point_at_real => x
  print *,point_at_real
  !!codesnippet end

end Program PointAtReal

