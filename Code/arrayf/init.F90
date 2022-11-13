!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** init.F90 : array initialization
!***
!****************************************************************

Program Init
  implicit none
  integer,parameter :: N=5
  integer :: i,lo,hi

  !!codesnippet farrayinit1
  real,dimension(5) :: real5 = [ 1.1, 2.2, 3.3, 4.4, 5.5 ]
  !!codesnippet end
  print *,real5

  !!codesnippet farrayinit2
  real5 = [ (1.01*i,i=1,size(real5,1)) ]
  !!codesnippet end
  print *,real5

  !!codesnippet farrayinit3
  real5 = (/ 0.1, 0.2, 0.3, 0.4, 0.5 /)
  !!codesnippet end
  print *,real5

End Program Init
