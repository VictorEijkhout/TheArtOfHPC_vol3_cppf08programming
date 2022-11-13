!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** mult1.F90 : Fortran OO program
!***
!****************************************************************

!!codesnippet fmult1type
Module multmod
  
  type Scalar
     real(4) :: value
   contains
     procedure,public :: &
          printme,scaled
  end type Scalar

contains ! methods
  !!codesnippet end

  !!codesnippet fmult1method
  subroutine printme(me)
    implicit none
    class(Scalar) :: me
    print '("The value is",f7.3)',me%value
  end subroutine printme
  function scaled(me,factor)
    implicit none
    class(Scalar) :: me
    real(4) :: scaled,factor
    scaled = me%value * factor
  end function scaled
  !!codesnippet end

!!codesnippet fmult1type
end Module multmod
!!codesnippet end

!!codesnippet fmult1prog
Program Multiply
  use multmod
  implicit none

  type(Scalar) :: x
  real(4) :: y
  x = Scalar(-3.14)
  call x%printme()
  y = x%scaled(2.)
  print '(f7.3)',y

end Program Multiply
!!codesnippet end
