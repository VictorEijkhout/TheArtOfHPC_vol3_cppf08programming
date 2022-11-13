!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** fib.F90 : recursive Fibonacci function
!***
!****************************************************************

program Factorial
  implicit none
  integer :: i,f
  read *,i
  f = fact(i)
  print *,i,"factorial is",f
contains
  !!codesnippet frecursf
  recursive integer function fact(invalue) &
       result (val)
    implicit none
    integer,intent(in) :: invalue
    if (invalue==0) then
       val = 1
    else
       val = invalue * fact(invalue-1)
    end if
  end function fact
  !!codesnippet end
end program Factorial
