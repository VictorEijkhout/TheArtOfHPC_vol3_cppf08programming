!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** storage.cxx : measure bit storage of floating types
!***
!****************************************************************

Program size
  implicit none

  interface twice
     integer function twice(i)
       integer,intent(in) :: i
     end function twice
   end function twice
     
  integer :: i=2,j
  j = twice(i)
  print *,j

contains

  integer function twice(i)
    integer,intent(in) :: i
    twice  = 2*i
  end function twice

end Program size
