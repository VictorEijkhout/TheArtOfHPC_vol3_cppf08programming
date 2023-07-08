!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** bigdata.F90 : beyond 32 bit indexing
!***
!****************************************************************

Program BigData
  use iso_c_binding
  implicit none
  integer,dimension(:,:),allocatable :: bigsquare
  integer,dimension(:),allocatable :: bigstraight
  integer,parameter :: k70 = 70000 ! more than 2^16
  integer, parameter :: bigint = selected_int_kind(18)
  integer(kind=bigint) :: k7070
  !integer :: k7070
  integer :: i16

  allocate(bigsquare(k70,k70))
  bigsquare(k70,k70) = 1
  print *,bigsquare(k70,k70)
  print *,shape(bigsquare)

  k7070 = k70 * k70
!  k7070 = k70 ; k7070 = k7070 * k70
  print *,"default ints are",c_sizeof(k70),"bytes"
  print *,"big size=",k7070,"; int of",c_sizeof(k7070),"bytes"
  allocate(bigstraight(k7070))
  print *,"actual result:",size(bigstraight),shape(bigstraight)
  bigstraight = reshape( bigsquare,shape(bigstraight) )
  print *,bigstraight(k7070)

End Program BigData
