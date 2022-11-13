!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** arraypass1d.F90 : passing a 1d array
!***
!****************************************************************

Module MatrixFunction
contains

  Subroutine diagonalize(x)
    implicit none
    real(8),intent(inout),dimension(:,:) ::x
    real(8) :: sum
    integer row,col

    do row=1,size(x,1)
       sum = 0.
       do col=1,size(x,2)
          sum = sum+x(row,col)
          x(row,col) = 0.
       end do
       x(row,row) = sum
    end do
    
  end Subroutine diagonalize

End Module MatrixFunction

Program ArrayComputations1D
    use MatrixFunction
    implicit none

    real(8),dimension(:) :: x(6,6)
    integer :: i,j

    do i=1,6
       do j=1,6
          x(i,j) = 1.
       end do
    end do
    call diagonalize(x)
    
    do i=1,6
       print *,(x(i,j),j=1,6)
    end do

End Program ArrayComputations1D



