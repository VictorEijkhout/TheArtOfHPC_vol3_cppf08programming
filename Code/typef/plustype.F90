!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** plustype.F90 : addition overloaded for type
!***
!****************************************************************

!!codesnippet ftypeadd
Module Typedef
  Type inttype
     integer :: value
  end type inttype
  Interface operator(+)
     module procedure addtypes
  end Interface operator(+)
contains
  function addtypes(i1,i2) result(isum)
    implicit none
    Type(inttype),intent(in) :: i1,i2
    Type(inttype) :: isum
    isum%value = i1%value+i2%value
  end function addtypes
end Module Typedef
!!codesnippet end

Program Reducttype
  use Typedef
  implicit none
  !!codesnippet ftypeadddo
  Type(inttype) :: i1,i2,i3
  i1 = inttype(1); i2 = inttype(2)
  i3 = i1+i2
  print *,"Sum:",i3%value
  !!codesnippet end
  
end Program Reducttype
