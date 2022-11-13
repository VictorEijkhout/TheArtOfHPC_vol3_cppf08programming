!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** arpoint.F90 : exercise solution about pointing into an array
!***
!****************************************************************


Program ArrayPoint

  implicit none

  !call random_number(array)

  real,dimension(10),target :: array &
       = [1.1, 2.2, 3.3, 4.4, 5.5, &
          9.9, 8.8, 7.7, 6.6, 0.0]
  real,pointer :: biggest_element

  print '(10f5.2)',array
  call SetPointer(array,biggest_element)
  print *,"Biggest element is",biggest_element
  print *,"checking pointerhood:",&
       associated(biggest_element)
  biggest_element = 0
  print '(10f5.2)',array

contains

  subroutine SetPointer(ar,pt)
    implicit none
    ! argument
    
  end subroutine SetPointer
  
end Program ArrayPoint
