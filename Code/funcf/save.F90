!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2019 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** save.F90 : initialized variables have implicit SAVE attribute
!***
!****************************************************************

Program FuncSave
  implicit none
  integer :: i,j

  i = 1; j = 3
  print '("Comparing:",i3,x,i3)',i,j
  print *,maxof2(1,3)
  i = -2; j = -4
  print '("Comparing:",i3,x,i3)',i,j
  print *,maxof2(-2,-4)

Contains
  !!codesnippet unsafesave
  integer function maxof2(i,j)
    implicit none
    integer,intent(in) :: i,j
    integer :: max=0
    if (i>max) max = i
    if (j>max) max = j
    maxof2 = max
  end function maxof2
  !!codesnippet end

end Program FuncSave
