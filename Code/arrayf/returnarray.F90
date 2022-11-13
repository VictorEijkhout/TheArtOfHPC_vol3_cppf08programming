!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** returnarray.F90 : array return from function
!***
!****************************************************************

Program ArrayReturn
  implicit none
  integer :: n
  real,dimension(:),allocatable :: v

  n = 5
  v = create_array(n)
  if ( .not. allocated(v) ) then
     print *,"Array was not allocated1"
     return
  end if
  print *,v

contains

  !!codesnippet returnarrayresult
  function create_array(n) result(v)
    implicit none
    integer,intent(in) :: n
    real,dimension(:),allocatable :: v
    integer  :: i
    allocate(v(n))
    v = [ (i+.5,i=1,n) ]
  end function create_array
  !!codesnippet end

End Program ArrayReturn

