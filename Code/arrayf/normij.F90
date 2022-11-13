!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** normij.F90 : matrix sums through array intrinsics
!***
!****************************************************************

Program NormIJ
  use Matrixpackage
  implicit none
  integer,parameter :: N=4
  integer,dimension(N,N) :: A
  integer,dimension(N) :: sums
  integer :: i,j

  ! Initialize the matrix
  A = reshape( &
       [ ( ( N*i+j, j=0,N-1 ), i=0,N-1 ) ], &
       shape(A) )
  print *,"Matrix:"
  print 10,A


  !!codesnippet frowcolsums
  ! Summing in I and J
  sums = Sum( A,dim=1 )
  print *,"Row sums:"
  print 10,sums

  sums = Sum( A,dim=2 )
  print *,"Column sums:"
  print 10,sums
10 format( 4(i3,1x) )
  !!codesnippet end

End Program NormIJ
