!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** readpos.F90 : exercise for function with intent out
!***
!****************************************************************

!!codesnippet readpos
program readpos
  implicit none
  real(4) :: userinput
  print *,"Type a positive number:"
  userinput = read_positive()
  print *,"Thank you for",userinput
contains
  real(4) function read_positive()
    implicit none
    !!codesnippet end
    real(4) :: maybe
    do
       read *,maybe
       if (maybe<=0) then
          print *,"No, not",maybe
       else
          read_positive = maybe
          exit
       end if
    end do
    !!codesnippet readpos
  end function read_positive
end program readpos
!!codesnippet end
