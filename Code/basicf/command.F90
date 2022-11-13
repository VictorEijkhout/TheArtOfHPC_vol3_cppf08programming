!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** command.F90 : commandline handling
!***
!****************************************************************

Program CommandLine
  implicit none
  !!codesnippet fargcstring
  character(len=10) :: size_string
  integer :: size_num
  !!codesnippet end

  !!codesnippet fargcount
  if (command_argument_count()==0) then
     print *,"This program needs an argument"
     stop 1
  end if
  !!codesnippet end
  
  !!codesnippet fargcstringread
  call get_command_argument(number=1,value=size_string)
  read(size_string,'(i3)') size_num
  !!codesnippet end
  print *,size_string
  print *,size_num

End Program CommandLine


