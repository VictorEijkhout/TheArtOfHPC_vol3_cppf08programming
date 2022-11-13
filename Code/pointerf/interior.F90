!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** interio.F90 : pointers into array slices
!***
!****************************************************************

Program Average
  implicit none
  integer,parameter :: N=5
  integer :: i,j,step

  !!codesnippet fpointinter
  real(4),target,allocatable,dimension(:,:) :: grid
  real(4),pointer,dimension(:,:) :: interior,left,right,up,down

  Allocate( grid(N,N) )
  !!codesnippet end

  call random_number(grid)
  
  !!codesnippet fpointinter
  interior => grid(2:N-1,2:N-1)
  up    => grid(1:N-2,2:N-1)
  down  => grid(3:N,2:N-1)
  left  => grid(2:N-1,1:N-3)
  right => grid(2:N-1,3:N)
  !!codesnippet end
  
  print 10,((grid(i,j),j=1,N),i=1,N)
  do step=1,10
     print '("step ",i1)',step
     !!codesnippet fpointinteravg
     interior = ( up+down+left+right )/4
     !!codesnippet end
     print 10,((grid(i,j),j=1,N),i=1,N)
  end do
10 format( 5( 5(f7.3,1x),/ ) )

End Program Average
