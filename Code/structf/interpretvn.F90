!! -*- f90 -*-
!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** interpretv.F90 : variable handling for the interpreter exercise
!***
!****************************************************************

type(namedvar) function varadd(op1,op2)
  implicit none
  type(namedvar),intent(in) :: op1,op2
  varadd%value = op1%value + op2%value
  write( varadd%expression, &
       '( "(", a, ")+(", a, ")" )' &
       ) trim( op1%expression ), trim( op2%expression )
end function varadd

type(namedvar) function varmult(op1,op2)
  implicit none
  type(namedvar),intent(in) :: op1,op2
  varmult%value = op1%value * op2%value
  write( varmult%expression, &
       '( "(",a,") * (",a,")" )' &
       ) trim( op1%expression ),trim( op2%expression )
end function varmult

type(namedvar) function varop(op1,op2,op)
  implicit none
  type(namedvar),intent(in) :: op1,op2
  character,intent(in) :: op
  if (op=="+") then
     varop = varadd(op1,op2)
  else if (op=="*") then
     varop = varmult(op1,op2)
  end if
end function varop


