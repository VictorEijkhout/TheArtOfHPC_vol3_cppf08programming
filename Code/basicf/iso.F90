!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** iso.F90 : iso bindings
!***
!****************************************************************

Program ISO
  !!codesnippet isoreal3264
  use iso_fortran_env
  implicit none
  real(kind=real32) :: x32
  real(kind=real64) :: x64
  print *,"32 bit max float:",huge(x32)
  print *,"64 bit max float:",huge(x64)
  !!codesnippet end

End Program ISO
