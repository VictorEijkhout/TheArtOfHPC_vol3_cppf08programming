!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** loopinf.F90 : infinite loop
!***
!****************************************************************

program loopinf
  implicit none
  integer :: i
  
  do 
     i = i+1

     if ( i>100 .and. i<150) cycle

     if (i==200) exit
     print *,i

  end do
  
end program loopinf
