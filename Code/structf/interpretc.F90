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

logical function islower(c)
  implicit none
  character,intent(in) :: c
  integer :: code, code_a,code_z
  code_a = iachar("a")
  code_z = iachar("z")
  code = iachar(c)
  islower = code.ge. code_a .and. code.le.code_z
end function islower

logical function isdigit(c)
  implicit none
  character,intent(in) :: c
  integer :: code, code_0,code_9
  code_0 = iachar("0")
  code_9 = iachar("9")
  code = iachar(c)
  isdigit = code.ge. code_0 .and. code.le.code_9
end function isdigit

logical function isop(c)
  implicit none
  character,intent(in) :: c
  integer :: code,code_p,code_m,code_t
  code_p = iachar("+")
  code_m = iachar("-")
  code_t = iachar("*")
  code = iachar(c)
  isop = code.eq. code_p .or. code.eq.code_m .or. code.eq.code_t
end function isop
