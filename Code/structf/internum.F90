!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** intermod.F90 : reverse polish interpreter
!***
!****************************************************************

Module CharHandling
contains
#include "interpretc.F90"
End Module CharHandling

Module VarHandling
  type namedvar
     character(len=20) :: expression
     integer :: value
  end type namedvar

  type(namedvar),dimension(10) :: stack
  integer :: stackpointer=0

contains

!!codesnippet fstackprintnum
subroutine stack_display()
  implicit none
  ! local variables
  integer :: istck

  if (stackpointer.eq.0) return
  print '( 10( a,a, a,i0,"; ") )', ( &
       " expr=",trim(stack(istck)%expression), &
       " val=",stack(istck)%value, &
       istck=1,stackpointer )         

end subroutine stack_display
!!codesnippet end

#include "interpretvn.F90"
!! #include "interpretsn.F90"
#include "interpretmn.F90"

End Module VarHandling

Program Interpreter
  use CharHandling
  use VarHandling
  implicit none

  character :: input

  do
     call stack_display()
     read *,input
     if (input .eq. '0') then
        exit
        !!codesnippet fstackpushcall
     else if ( isdigit(input) ) then
        call stack_push(input)
        !!codesnippet end
        !!codesnippet fstackopcall
     else if ( isop(input) ) then
        call stack_op(input)
        !!codesnippet end
     ! else if ( islower(input) ) then
     !    call stack_name(input)
     end if
  end do
  
end Program Interpreter
