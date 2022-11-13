!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** mult2.F90 : incorrect OO program
!***
!****************************************************************

Module multmod
  
  type Scalar
     real(4) :: value
   contains
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
  end type Scalar
  
end Module multmod

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
