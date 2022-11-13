!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** jordan.F90 : Gauss Jordan elimination
!***
!****************************************************************

Program GaussJordan
  implicit none
  integer,parameter :: N=6
  real(8),dimension(N,N) :: matrix
  real(8),dimension(N) :: scalings
  integer :: row,col,piv
  real(8) :: pivot

  ! Initialize the matrix
  call random_number(matrix)
  do row=1,N
     matrix(row,row) = N
  end do

  do piv=1,N
     pivot = matrix(piv,piv)
     scalings = matrix(:,piv)/pivot
  end do

  do row=1,N
     print *,(matrix(row,col),col=1,N)
  end do

End Program GaussJordan
