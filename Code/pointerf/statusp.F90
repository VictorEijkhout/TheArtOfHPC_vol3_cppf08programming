!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** statusp.F90 : pointer status
!***
!****************************************************************


Program AssocStatus

  implicit none

  !!codesnippet pointfstatus
  real,target :: x
  real,pointer :: realp

  print *,"Pointer starts as not set"
  if (.not.associated(realp)) &
     print *,"Pointer not associated"
  x = 1.2
  print *,"Set pointer"
  realp => x
  if (associated(realp)) &
     print *,"Pointer points"
  print *,"Unset pointer"
  nullify(realp)
  if (.not.associated(realp)) &
     print *,"Pointer not associated"
  !!codesnippet end

End Program AssocStatus

