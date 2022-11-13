!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** interpret.F90 : reverse polish interpreter
!***
!****************************************************************

!!codesnippet fstackpushdef
subroutine stack_push(input)
  implicit none
  character,intent(in) :: input
!!codesnippet end

  stackpointer = stackpointer + 1
  read( input,'( i1 )' ) stack(stackpointer)%value
  stack(stackpointer)%id = "."
  stack(stackpointer)%expression = trim(input)
end subroutine stack_push

subroutine stack_op(input)
  implicit none
  character,intent(in) :: input
  type(namedvar) :: op1,op2

  op2 = stack(stackpointer)
  stackpointer = stackpointer-1
  op1 = stack(stackpointer)
  stack(stackpointer) = varop(op1,op2,input)
end subroutine stack_op

!!NOID
subroutine stack_name(input)
  implicit none
  character,intent(in) :: input
  integer :: stacksearch

  stacksearch = find_on_stack(stack,stackpointer,input)
  if ( stacksearch>=1 ) then
     stackpointer = stackpointer+1
     stack(stackpointer) =  stack(stacksearch)
  else
     stack(stackpointer)%id = input
  end if
end subroutine stack_name
!!noid
