!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** interface.F90 : explicit interfaces
!***
!****************************************************************

Program HasInterface
  implicit none
  integer :: i

  !!codesnippet interfacemain
  interface
     function f(x,y)
       real*8 :: f
       real*8,intent(in) :: x,y
     end function f
  end interface
  
  real*8 :: in1=1.5, in2=2.6, result

  result = f(in1,in2)
  !!codesnippet end
  print *,result
  

end Program HasInterface


  
