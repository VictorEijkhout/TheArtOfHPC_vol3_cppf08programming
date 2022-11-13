!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** protect.F90 : demonstrate the protected keyword
!***
!****************************************************************

!!codesnippet protectmod
Module settings
  implicit none
  logical,protected :: has_been_initialized = .FALSE.
contains
  subroutine init()
    has_been_initialized = .TRUE.
  end subroutine init
End Module settings
!!codesnippet end

Program TestSettings
  use settings
  implicit none

!!codesnippet protectmain
  if ( .not. has_been_initialized ) then
     call init()
  end if
  !! WRONG does not compile:
  ! has_been_initialized = .FALSE.
!!codesnippet end

end Program TestSettings
