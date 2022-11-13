!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** loopr.F90 : real loop index
!***
!****************************************************************

program loops
  implicit none
  !!codesnippet fdoreal
  real(4) :: r
  
  do r=.1,1.,.1
     print *,r
  end do
  !!codesnippet end
  
end program loops
