!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** intermod.F90 : reverse polish interpreter
!***
!****************************************************************

Module StackClass
  type namedvar
     character :: id
     character(len=20) :: expression
     integer :: value
  end type namedvar

  !!codesnippet fstackclass
  type stackstruct
     type(namedvar),dimension(10) :: data
     integer :: top=0
   contains
     procedure,public :: display, find_id, name, op, push
  end type stackstruct
  !!codesnippet end

  interface operator(+)
     module procedure varadd
  end interface operator(+)
  interface operator(*)
     module procedure varmult
  end interface operator(*)

contains


! overloading arithmetic
#include "interpretov.F90"
! character handling
#include "interpretc.F90"
! stack handling, class version
#include "interpretsc.F90"
#include "interpretmc.F90"

End Module StackClass

Program Interpreter
  use StackClass
  implicit none

  type(stackstruct) :: thestack
  character :: input

  do
     call thestack%display()
     read *,input
     if (input .eq. '0') exit
     !!codesnippet fstackpusho
     if ( isdigit(input) ) then
        call thestack%push(input)
     !!codesnippet end
     else if ( isop(input) ) then
        call thestack%op(input)
     else if ( islower(input) ) then
        call thestack%name(input)
     end if
  end do
  
end Program Interpreter
