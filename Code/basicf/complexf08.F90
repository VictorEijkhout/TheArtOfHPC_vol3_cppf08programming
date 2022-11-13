!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** complex.F90 : basic complex stuff
!***
!****************************************************************

Program TestComplex
  implicit none

  Type(Complex) :: &
       fourtyfivedegrees = (1.,1.), &
       number,rotated
  Real :: x,y
  !!codesnippet fcomplexf08
  print *,"45 degrees:",fourtyfivedegrees
  x = 3. ; y = 1.; number = cmplx(x,y)
  rotated = number * fourtyfivedegrees
  print '("Rotated number has Re=",f5.2," Im=",f5.2)',&
       rotated%re,rotated%im
  !!codesnippet end
  
End Program TestComplex

