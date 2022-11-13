!****************************************************************
!****
!**** This file belongs with the course
!**** Introduction to Scientific Programming in C++/Fortran2003
!**** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!****
!**** point.F90 : make a Point class
!****
!****************************************************************


Module PointMod

  Type,public :: Point
     real(8) :: x,y
  End type Point

contains

  subroutine set(p,xu,yu)
    implicit none
    type(point) :: p
    real(8),intent(in) :: xu,yu
    p%x = xu; p%y = yu
  end subroutine set

  real(8) function distance(self,other)
    implicit none
    type(point) :: self,other

    real(8) :: dx,dy
    dx = self%x-other%x; dy = self%y-other%y
    distance = sqrt( dx*dx + dy*dy )
  End function distance

End Module PointMod
