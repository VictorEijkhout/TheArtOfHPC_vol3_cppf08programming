!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** real.F90 : pointer to real
!***
!****************************************************************


Program PointAtReal

  implicit none

  !!codesnippet pointatreal
  real,target :: x,y
  real,pointer :: that_real

  x = 1.2
  y = 2.4
  that_real => x
  print *,that_real
  that_real => y
  print *,that_real
  y = x
  print *,that_real
  !!codesnippet end

end Program PointAtReal

