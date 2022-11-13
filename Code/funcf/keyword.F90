!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** keyword.F90 : function call with keywords
!***
!****************************************************************

program keyword
  implicit none
  integer :: i
  !!codesnippet sayxykw
  call say_xy(1,2)
  call say_xy(x=1,y=2)
  call say_xy(y=2,x=1)
  call say_xy(1,y=2)
  ! call say_xy(y=2,1) ! ILLEGAL
contains
  subroutine say_xy(x,y)
    implicit none
    integer,intent(in) :: x,y
    print *,"x=",x,", y=",y
  end subroutine say_xy
  !!codesnippet end
end program keyword
