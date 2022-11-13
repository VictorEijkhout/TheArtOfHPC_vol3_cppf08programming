!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** quicksort.F90 : sorting
!***
!*** UNFINISHED
!***
!****************************************************************

Program SortTest
  implicit none
  integer :: N,i
  real :: randomvalue
  integer,dimension(:),allocatable :: values

  read *,N
  allocate(values(N))
  do i=1,size(values)
     call random_number(randomvalue)
     values(i) = N*randomvalue
  end do
  print *,values

contains
  subroutine redwhiteblue( values,median,len_red,len_blue)
    implicit none
    integer,dimension(:),intent(inout) :: values
    integer,intent(in) :: median
    integer,intent(out) :: len_red,len_blue
    ! local variables
    integer :: lvalue,rvalue

    len_red = 0
    do
       lvalue = values(len_red+1)
       if (lvalue<median) then
          len_red = len_red+1
       else
          exit
       end if
    end do
    len_blue = 0
    rvalue = values( size(values)-len_blue )
    
  end subroutine redwhiteblue
  recursive subroutine quicksort( values )
    implicit none
    integer,dimension(:),intent(inout) :: values
    integer :: median,len_red,len_blue

    if (size(values)==1) then
       return
    else
       median = values(1)
       call redwhiteblue(values,median,len_red,len_blue)
       call quicksort( values(1:len_red) )
       call quicksort( values( size(values)-len_blue+1:size(values) ) )
    end if
    
  end subroutine quicksort

End Program SortTest
