!****************************************************************
!****
!**** This file belongs with the course
!**** Introduction to Scientific Programming in C++/Fortran2003
!**** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!****
!**** scalar.F90 : geometry with operator overloading
!****
!****************************************************************

Module Physics

  !!codesnippet fscalarfield
  Type,public :: ScalarField
     real(8) :: value
   contains
     procedure,public :: set,print
     procedure,public :: add
  End type ScalarField
  !!codesnippet end

  !!codesnippet fscalarplusop
  interface operator(+)
     module procedure add
  end interface operator(+)
  !!codesnippet end

contains

  !!codesnippet fscalarsetprint
  subroutine set(v,x)
    implicit none
    class(ScalarField) :: v
    real(8),intent(in) :: x

    v%value = x
  end subroutine set

  subroutine print(v)
    implicit none
    class(ScalarField) :: v

    print '(f7.4)', v%value
  end subroutine print
  !!codesnippet end

  !!codesnippet fscalaradd
  function add(in1,in2) result(out)
    implicit none
    class(ScalarField),intent(in) :: in1
    type(ScalarField),intent(in) :: in2
    type(ScalarField) :: out

    out%value = in1%value + in2%value
  end function add
  !!codesnippet end

End Module Physics

Program Simulation
  use Physics
  implicit none
  integer,parameter :: size = 12

  Type(ScalarField) :: u,v,z

  !!codesnippet fscalarsetprintuse
  call u%set(2.d0)
  call v%set(1.d0)
  !  z = u%add(v)
  z = u+v
  !!codesnippet end
  
  call z%print()

End Program Simulation

