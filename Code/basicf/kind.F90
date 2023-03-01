!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** kind.F90 : type selection by kind
!***
!*** this example from: https://fortranwiki.org/fortran/show/selected_real_kind
!***
!****************************************************************

Program Kind
  implicit none
  
  !!codesnippet frealkind
  integer,parameter :: &
       i12 = selected_int_kind(12), &
       p6 = selected_real_kind(6), &
       p10r100 = selected_real_kind(10,100), &
       r400 = selected_real_kind(r=400), &
       p20 = selected_real_kind(20), &
       p40 = selected_real_kind(40)
  integer(kind=i12) :: i
  real(kind=p6) :: x
  real(kind=p10r100) :: y
  real(kind=r400) :: z
  real(kind=p20) :: p
  !!codesnippet end

  print 8,"Kinds:",i12,p6,p10r100,r400,p20,p40
8 format(a8,6i5)
  print *,"Precision / range / bits:"
  print 10, "integer 12 :",0,            range(i),storage_size(i)
  print 10, "precision 6:",precision(x), range(x),storage_size(x)
  print 10, "p=10 r=100 :",precision(y), range(y),storage_size(y)
  print 10, "range=400  :",precision(z), range(z),storage_size(z)
  print 10, "p=20       :",precision(p), range(p),storage_size(p)
10 format(a14,4i5)

End Program Kind
