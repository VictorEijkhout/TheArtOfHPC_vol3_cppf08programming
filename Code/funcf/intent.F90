!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** intent.F90 : parameter intent
!***
!****************************************************************

Program ContainsScope
  implicit none
  real :: x

  x = 5
  call ArgIn (x)
  print *,x
  
Contains
  !!codesnippet arginwrong
  subroutine ArgIn(x)
    implicit none
    real,intent(in) :: x
    x = 5 ! compiler complains
  end subroutine ArgIn
  !!codesnippet end
  subroutine ArgOut(x)
    implicit none
    real,intent(out) :: x
    x = 5
  end subroutine ArgOut

end Program ContainsScope

  
