!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** ieee.F90 : IEEE 754 quantities
!***
!****************************************************************

Program IEEE
  use,intrinsic :: ieee_arithmetic
  implicit none
  
  integer,parameter :: single_type = ieee_selected_real_kind(5,20)
  real :: NaNdefault,Infdefault
  real(kind=single_type) :: NaNsingle,Infsingle

  !  Infdefault = ieee_value( 0,0, ieee_positive_inf )
  !  Infdefault = r_infinity()

  ! NaNdefault = ieee_value( 0,0, ieee_quiet_nan )
  ! NaNsingle  = ieee_value( 0,0, ieee_quiet_nan )

End Program IEEE
