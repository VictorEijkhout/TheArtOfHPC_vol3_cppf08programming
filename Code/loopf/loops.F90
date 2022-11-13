!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** loops.F90 : exploring the upper bound
!***
!****************************************************************

program loops
  implicit none
  integer :: i,j
  
  do i=1,11,3
     print *,i
  end do

  do i=1,3,11
     print *,i
  end do
  
end program loops
