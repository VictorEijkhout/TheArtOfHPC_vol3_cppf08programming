!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** forallar.F90 : 
!***
!****************************************************************


Program CopySlice

  implicit none

  integer,parameter :: n = 10
  integer, dimension(n) :: counting,counted
  integer :: i,s=0

  
  forall (i=1:n)
     counting(i) = i
     s = s+counting(i)
  end forall

end Program CopySlice

