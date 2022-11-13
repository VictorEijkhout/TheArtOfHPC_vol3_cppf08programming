!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2020 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** adjust.F90 : adjusted output
!***
!****************************************************************

Program Adjust
  implicit none
  integer :: i = 1
  real    :: x = 2.3
  character(len=2) :: c = "fv"
  character(len=8) :: i_head,x_head,c_head,p_head
  character(len=8) :: i_string,x_string,c_string

  print *,"header literal"
  print '(a24)',"|2345678|2345678|2345678"
  print '(4a8)', "Int","Real","String","."
  print *,""

  print *,"header strings"
  print '(a24)',"|2345678|2345678|2345678"
  i_head = "Int"; x_head = "Real"
  c_head = "String"; p_head = "."
  print '(4a8)', i_head,x_head,c_head,p_head
  print *,""

  print *,"values star"
  print '(a24)',"|2345678|2345678|2345678"
  print *,i,x,c
  print *,""

  print *,"values 8"
  print '(a24)',"|2345678|2345678|2345678"
  print '(i8,f8.5,a8)',i,x,c
  print *,""

  print *,"values left adjust"
  print '(a24)',"|2345678|2345678|2345678"
  print '(i0,f0.3,a8)',i,x,c
  print *,""

  print *,"left"
  print '(a24)',"|2345678|2345678|2345678"
  write(i_string,'(i8)') i
  write(x_string,'(f8.5)') x
  write(c_string,'(a8)') c
  !adjustl(i_string); adjustl(x_string); adjustl(c_string)
  print '(4a8)',i_string,x_string,c_string,p_head
  print *,""
end Program Adjust
