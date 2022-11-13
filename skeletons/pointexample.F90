!****************************************************************
!****
!**** This file belongs with the course
!**** Introduction to Scientific Programming in C++/Fortran2003
!**** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
!****
!**** pointexample.F90 : example for the textbook exercise
!****
!****************************************************************

  real(8) function distance(me,other)
    implicit none
    class(Point) :: me
    type(Point),intent(in) :: other
    real(8) :: dx,dy
    dx = me%x-other%x; dy = me%y-other%y
    distance = sqrt( dx**2 + dy**2 )
  end function distance

