!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** arraypass1d.F90 : passing a 1d array
!***
!****************************************************************

Module ArrayFunction
contains

  !!codesnippet fpass1dsubr
  real(8) function arraysum(x)
    implicit none
    real(8),intent(in),dimension(:) :: x
    real(8) :: tmp
    integer i

    tmp = 0.
    do i=1,size(x)
       tmp = tmp+x(i)
    end do
    arraysum = tmp
  end function arraysum
  !!codesnippet end

End Module ArrayFunction

#define N 10
Program ArrayComputations1D
    use ArrayFunction
    implicit none

    integer :: i
    real(8) :: sx,sy

    !!codesnippet fpass1dmain
    real(8),dimension(:) :: x(N) &
         = [ (i,i=1,N) ]
    real(8),dimension(:) :: y(0:N-1) &
         = [ (i,i=1,N) ]

    sx = arraysum(x)
    sy = arraysum(y)
    print '("Sum of one-based array:",/,4x,f6.3)', sx
    print '("Sum of zero-based array:",/,4x,f6.3)', sy
    !!codesnippet end

End Program ArrayComputations1D



