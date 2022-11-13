!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2018-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** query.F90 : array query functions
!***
!****************************************************************

Program Query
  implicit none

  !!codesnippet farrayquery
  integer,dimension(8) :: x
  integer,dimension(5,3:7) :: y
  !!codesnippet end

  !!codesnippet lubound
  real,dimension(-1:7) :: array
  integer :: idx
  !!codesnippet end

  print *,"Q"
  !!codesnippet farrayquery
  print '("size x     :",2i3)',size(x)
  print '("size y     :",2i3)',size(y)
  print '("size y in 2:",2i3)',size(y,2)
  print '("lbound y   :",2i3)',lbound(y)
  print '("ubound y1  :",2i3)',ubound(y,1)
  !!codesnippet end
  print *,"q"

  print *,"LU"
  !!codesnippet lubound
  do idx=lbound(array,1),ubound(array,1)
     array(idx) = 1+idx/10.
     print *,array(idx)
  end do
  !!codesnippet end
  print *,"lu"

End Program Query
