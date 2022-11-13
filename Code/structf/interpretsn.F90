!! -*- f90 -*-
!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** interpretc.F90 : character handling for the interpreter exercise
!***
!****************************************************************

subroutine stack_print(stack,top)
  implicit none
  type(namedvar),dimension(:),intent(in) :: stack
  integer,intent(in) :: top
  ! local variables
  integer :: istck

  if (top.eq.0) return
  print '( 10( a,a1, a,a, a,i0,"; ") )', ( &
       " expr=",trim(stack(istck)%expression), &
       " val=",stack(istck)%value, &
       istck=1,top )         

end subroutine stack_print

