!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** forallshift.F90 : forall statement
!***
!****************************************************************

Program ForShift
  implicit none
  integer,parameter :: N=5
  integer :: i,lo,hi

  integer,dimension(N) :: A

  print *,"Traditional loop, forward"
  !!codesnippet forfor
  A = [1,2,3,4,5]
  do i=1,4
     A(i+1) = A(i)
  end do
  print '(5(i2x))',A
  !!codesnippet end

  print *,"Forall loop, forward"
  print *,"FF"
  !!codesnippet forallf
  A = [1,2,3,4,5]
  forall (i=1:4)
     A(i+1) = A(i)
  end forall
  print '(5(i2x))',A
  !!codesnippet end
  print *,"ff"
  
  print *,"Traditional loop, backward"
  !!codesnippet forbac
  A = [1,2,3,4,5]
  do i=4,1,-1
     A(i+1) = A(i)
  end do
  print '(5(i2x))',A
  !!codesnippet end

  print *,"Forall loop, backward"
  print *,"BB"
  !!codesnippet forallb
  A = [1,2,3,4,5]
  do i=4,1,-1
     A(i+1) = A(i)
  end do
  print '(5(i2x))',A
  !!codesnippet end
  print *,"bb"

End Program ForShift
