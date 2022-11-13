!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** section.F90 : array sections
!***
!****************************************************************

Program Norms
  implicit none
  integer,parameter :: N=5
  integer :: i,lo,hi

  !!codesnippet fsection1
  real(8),dimension(N) :: Afrom1 = [1,2,3,4,5]
  !!codesnippet end

  !!codesnippet fsection2
  real(8),dimension(2:N+1) :: Afrom2 = &
       [1,2,3,4,5]
  !!codesnippet end

  !!codesnippet fsectionassign
  real(8),dimension(5) :: x = &
       [.1d0, .2d0, .3d0, .4d0, .5d0]
  !!codesnippet end

  !!codesnippet fsectionmg
  integer,dimension(5) :: &
       y = [0,0,0,0,0]
  integer,dimension(3) :: &
       z = [3,3,3]
  !!codesnippet end

  !!codesnippet fsection1
  lo = lbound(Afrom1,1); hi = ubound(Afrom1,1)
  print *,lo,hi
  print *,(i,":",Afrom1(i),i=lo,hi)
  !!codesnippet end

  print *,"Fsection2"
  !!codesnippet fsection2
  lo = lbound(Afrom1,1)
  hi = ubound(Afrom1,1)
  print *,lo,hi
  print '(i3,":",f5.3)', &
       (i,Afrom1(i),i=lo,hi)
  !!codesnippet end
  print *,"fsection2"

  print *,"SectionAssign"
  !!codesnippet fsectionassign
  x(2:5) = x(1:4)
  print '(f5.3)',x
  !!codesnippet end
  print *,"sectionassign"

  print *,"SectionMg"
  !!codesnippet fsectionmg
  y(1:5:2) = z(:)
  print '(i3)',y
  !!codesnippet end
  print *,"sectionmg"

End Program Norms
