! -*- f90 -*-
!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** typemod.F90 : modules containing types and such
!***
!****************************************************************

!!codesnippet pointmod
Module geometry
  type point
     real :: x,y
  end type point
  real(8),parameter :: pi = 3.14159265359
contains
  real(4) function length(p)
    implicit none
    type(point),intent(in) :: p
    length = sqrt( p%x**2 + p%y**2 )
  end function length
end Module geometry
!!codesnippet end

!!codesnippet pointmodprog
Program size
  use geometry
  implicit none

  type(point) :: p1,p2
  p1 = point(2.5, 3.7)

  p2 = p1
  print *,p2%x,p2%y
  print *,"length:",length(p2)
  print *,2*pi

end Program size
!!codesnippet end
