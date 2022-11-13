!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** shortcut.F90 : F90 has no shortcut AND/OR. it may work, it may not
!***
!****************************************************************

Program Cut
  implicit none

  real(4) :: x
  print *,"Input a real number:"
  read *,x
  if ( x>=0 .AND. sqrt(x)<3.15 ) then
     print *,"Under ten"
  end if

End Program Cut
