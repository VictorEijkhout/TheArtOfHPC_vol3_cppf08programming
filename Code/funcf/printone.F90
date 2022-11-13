!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2018-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** printone.F90 : trivial subroutine
!***
!****************************************************************

!!codesnippet fprintone
program printone
  implicit none
  call printint(5)
contains
  subroutine printint(invalue)
    implicit none
    integer :: invalue
    print *,invalue
  end subroutine printint
end program printone
!!codesnippet end
