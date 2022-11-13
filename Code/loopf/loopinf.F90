!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** loopinf.F90 : infinite loop
!***
!****************************************************************

program loopinf
  implicit none
  integer :: i,j
  
  do i=1,-1,2
     print *,i
  end do
  
end program loopinf
