!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** parampoint.F90 : parametrized derived tpyes
!***
!****************************************************************

Program size
  implicit none

  !!codesnippet ftypedefd
  type point(dim)
     integer,len :: dim
     real,dimension(dim) :: x
  end type point
  !!codesnippet end

  !!codesnippet ftypeused
  type(point(3)) :: p1,p2
  p1%x = [1.,2.,3.]

  p2 = p1
  print *,p2%x
  !!codesnippet end
  
  !!codesnippet ftypecalld
  print *,"Length:",length(p2)
  !!codesnippet end
  
contains
  !!codesnippet ftypepassd
  real(4) function length(p)
    implicit none
    type(point(3)),intent(in) :: p
    length = sqrt( &
         p%x(1)**2 + p%x(2)**2 + p%x(3)**2 )
  end function length
  !!codesnippet end
  
end Program size
