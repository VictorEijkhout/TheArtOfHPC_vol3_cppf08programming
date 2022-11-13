!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** module.F90 : simple use of modules
!***
!****************************************************************

!!codesnippet modulef
Module FunctionsAndValues
  implicit none

  real(8),parameter :: pi = 3.14

contains
  subroutine SayHi()
    implicit none
    print *,"Hi!"
  end subroutine SayHi
  
End Module FunctionsAndValues
!!codesnippet end

!!codesnippet moduleuse
Program ModProgram
  use FunctionsAndValues
  implicit none

  print *,"Pi is:",pi
  call SayHi()

End Program ModProgram
!!codesnippet end
