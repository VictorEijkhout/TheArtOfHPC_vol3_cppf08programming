!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** multi.F90 : array multi functions
!***
!****************************************************************

Program Multi
  implicit none

  integer :: i,j
  !!codesnippet finit2d
  real,dimension(2,2) :: x
  x = reshape( [ ( 1.*i,i=1,size(x) ) ], shape(x) )
  print *,x
  !!codesnippet end

End Program Multi
