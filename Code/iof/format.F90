!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2019 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** format.F90 : illustrations of Fortran formats
!***
!****************************************************************

Program Formats
  implicit none
  integer :: i,j,k

  print *,'I4'
  !!codesnippet i4
  i = 56
  print *,i
  print '(i4)',i
  print '(i2)',i
  print '(i1)',i
  i = i*i
  print '("fit <",i0,"> ted")',i
  !!codesnippet end
  print *,'i4'

  print *,'II'
  !!codesnippet ii
  i = 12; j = 34
  print '(2i4)',i,j
  print '(2i2)',i,j
  !!codesnippet end
  print *,'ii'

  print *,'IJ'
  !!codesnippet ij
  i = 23; j = 45; k = 67
  print '(i2,1x,i2)',i,j
  print '("Numbers:",3(1x,i2,"."))', i,j,k
  !!codesnippet end
  print *,'ij'

end Program Formats
