!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** shape.F90 : array reshaping
!***
!****************************************************************

Program Shape
  implicit none
  integer,parameter :: N=5
  integer :: i,j

  real(4),dimension(4,4) :: square
  real(4),dimension(2,8) :: rect
  real(4),dimension(3,5) :: nofit

  !!codesnippet shape44
  square = reshape( (/(i,i=1,16)/),(/4,4/) )
  !!codesnippet end

!  print *,shape(square)
  print '(4(f6.3x))',square
!  print *,( (square(i,j),i=1,4), j=1,4 )

End Program Shape
