!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** inttypes.F90 : passing a 1d array
!***
!****************************************************************

Program inttypes
  use iso_fortran_env
  implicit none

  !!codesnippet fisokinds
  Integer(kind=Int8) :: i8
  Integer(kind=Int16) :: i16
  Integer(kind=Int32) :: i32
  Integer(kind=Int64) :: i64
  !!codesnippet end
#if defined(COMPILERgcc)
  Integer(kind=16) :: i128
#endif

  !!codesnippet fisosizes
  print 10,"Checking on supported types:"
  print 10,"number of defined int types:",size(INTEGER_KINDS)
  print 10,"these are the supported types:",INTEGER_KINDS
  print 15,"Pre-defined types INT8,INT16,INT32,INT64:",&
       INT8,INT16,INT32,INT64
  print *
  print 20,"kind Int8 max is",huge(i8)
  print 20,"kind Int16 max is",huge(i16)
  print 20,"kind Int32 max is",huge(i32)
  print 20,"kind Int64 max is",huge(i64)
  !!codesnippet end
#if defined(COMPILERgcc)
  print *,"kind KINDS[5]=16 max is",huge(i128)
#endif
10 format( a30,4(i3,1x) )
15 format( a40,/,30x,4(i3,1x) )
20 format( a20,i20 )

end Program inttypes
