!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** deftypes.F90 : range of default types
!***
!****************************************************************

Program deftypes
  implicit none

  !!codesnippet fdeftypes
  Integer :: idef
  Real :: rdef
  Real(8) :: rdouble

  print 10,"integer is kind",kind(idef)
  print 10,"integer max is",huge(idef)
  print 10,"real is kind",kind(rdef)
  print 15,"real max is",huge(rdef)
  print 10,"real8 is kind",kind(rdouble)
  print 15,"real8 max is",huge(rdouble)
  !!codesnippet end

10 format( a16,1x,i10 )
15 format( a16,1x,e10.4 )

end Program deftypes
