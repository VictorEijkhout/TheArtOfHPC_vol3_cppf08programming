!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** labeled.F90 : labeled loops
!***
!****************************************************************

program looping
  implicit none
  integer :: i,j
  
  !!codesnippet flooplabel
  outer: do i=1,10
     inner: do j=1,10
        test: if (i*j>42) then
           print *,i,j
           exit outer
        end if test
     end do inner
  end do outer
  !!codesnippet end
  
end program looping
