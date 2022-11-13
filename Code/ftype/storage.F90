!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!
!!!! This file belongs with the course
!!!! Introduction to Scientific Programming in C++/Fortran2003
!!!! copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!!!!
!!!! storage.cxx : measure bit storage of floating types
!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Program size

  use iso_c_binding

  implicit none

  !!codesnippet fstorage
  integer(2) :: i2
  integer(4) :: i4
  integer(8) :: i8

  real(4) :: r4
  real(8) :: r8
  real(16) :: r16

  complex(8) :: c8
  complex(16) :: c16
  complex*32 :: c32
  !!codesnippet end

  print *,"integer(2) takes:",storage_size(i2),bit_size(i2)
  print *,"integer(4) takes:",storage_size(i4),bit_size(i4)
  print *,"integer(8) takes:",storage_size(i8),bit_size(i8),c_sizeof(i8)

  print *,"real(4) takes:",storage_size(r4)
  print *,"real(8) takes:",storage_size(r8)
  print *,"real(16) takes:",storage_size(r16),c_sizeof(r16)
  
  print *,"complex(8) takes:",storage_size(c8),c_sizeof(c8)
  print *,"complex(16) takes:",storage_size(c16),c_sizeof(c16)
  print *,"complex(32) takes:",storage_size(c32),c_sizeof(c32)
  
end Program size
