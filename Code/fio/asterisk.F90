!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** asterisk.cxx : Fortran I/O
!***
!****************************************************************

Program Asterisk
  implicit none

  integer :: ipower,number=1

  !!codesnippet fasterisk
  do ipower=1,5
     print '(i3)',number
     number = 10*number
  end do
  !!codesnippet end
  
end Program Asterisk
