!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** binding.F90 : iso C bindings
!***
!****************************************************************

Program ISO
  !!codesnippet isocbind
  use iso_c_binding
  implicit none
  integer,parameter :: &
       p6 = selected_real_kind(6), &
       p12 = selected_real_kind(12)
  real(kind=p6) :: x4
  real(kind=p12) :: x8
10 format(i2" digits takes",i3," bytes")
  print 10,6,c_sizeof(x4)
  print 10,12,c_sizeof(x8)
  !!codesnippet end

End Program ISO
