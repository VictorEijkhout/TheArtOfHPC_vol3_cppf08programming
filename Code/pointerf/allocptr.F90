!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** allocptr.F90 : allocate the pointer object
!***
!****************************************************************


Program PointAtReal

  implicit none

  !!codesnippet fptralloc
  Real,pointer :: x_ptr,y_ptr
  allocate(x_ptr)
  y_ptr => x_ptr
  x_ptr = 6
  print *,y_ptr
  !!codesnippet end

end Program PointAtReal

