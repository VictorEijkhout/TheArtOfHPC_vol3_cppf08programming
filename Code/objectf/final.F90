!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** final.F90 : Fortran OO program with finalizer
!***
!****************************************************************

Module multmod
  
  type Scalar
     real(4) :: value
     !!codesnippet finaldecl
   contains
     final :: &
          print_final
  end type Scalar
  !!codesnippet end

contains ! methods

  !!codesnippet finalproc
  subroutine print_final(me)
    implicit none
    type(Scalar) :: me
    print '("On exit: value is",f7.3)',me%value
  end subroutine print_final
  !!codesnippet end

end Module multmod

Program Finalize
  use multmod
  implicit none
  !!codesnippet finaluse
  call tmp_scalar()
contains
  subroutine tmp_scalar()
    type(Scalar) :: x
    real(4) :: y
    x = Scalar(-3.14)
  end subroutine tmp_scalar
  !!codesnippet end
end Program Finalize
