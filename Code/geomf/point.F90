!****************************************************************
!****
!**** This file belongs with the course
!**** Introduction to Scientific Programming in C++/Fortran2003
!**** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!****
!**** point.F90 : make a Point class
!****
!****************************************************************

!!codesnippet classmodule
Module PointClass
  !!codesnippet end

  !!codesnippet pointdeff
  Type,public :: Point
     real(8) :: x,y
   contains
     procedure, public :: setzero
     procedure, public :: set
     procedure, public :: length
     procedure, public :: distance
  End type Point
  !!codesnippet end

  !!codesnippet classmodule
  private
contains
  subroutine setzero(p)
    implicit none
    class(point) :: p
    p%x = 0.d0 ; p%y = 0.d0
  end subroutine setzero
  !!codesnippet end

  !!codesnippet pointsetf
  subroutine set(p,xu,yu)
    implicit none
    class(point) :: p
    real(8),intent(in) :: xu,yu
    p%x = xu; p%y = yu
  end subroutine set
  !!codesnippet end

  real(8) function length(self)
    implicit none
    class(point) :: self

    real(8) :: dx,dy
    dx = self%x; dy = self%y
    length = sqrt( dx*dx + dy*dy )
  End function length

  real(8) function distance(self,other)
    implicit none
    class(point) :: self,other

    real(8) :: dx,dy
    dx = self%x-other%x; dy = self%y-other%y
    distance = sqrt( dx*dx + dy*dy )
  End function distance

  !!codesnippet classmodule
End Module PointClass
!!codesnippet end

Program PointTest
  !!codesnippet pointusef
  use PointClass
  implicit none
  type(Point) :: p1,p2

  call p1%set(1.d0,1.d0)
  call p2%set(4.d0,5.d0)
  !!codesnippet end

  print *,"Length:",p1%length()
  print *,"Distance:",p1%distance(p2)

End Program PointTest

