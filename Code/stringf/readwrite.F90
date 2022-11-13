!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** readwrite.F90 : string conversions
!***
!****************************************************************

Program ReadWrite
  implicit none

  !!codesnippet flongdate
  character(len=10) :: longdate
  !!codesnippet end

  !!codesnippet fdatestr
  character(len=8) :: date
  integer :: year,month,day
  date = "20221027"
  read( date,'( i4,i2,i2 )' ) &
       year,month,day
  !!codesnippet end
  print *,"RW"
  !!codesnippet fdatestr
  print *,"Date:",date
  print '( "Year=",i4,", mo=",i2,", day=",i2 )', &
       year,month,day
  !!codesnippet end
  print *,"rw"

  print *,"Slash"
  !!codesnippet flongdate
  write( longdate,&
       '( i4,"/",i2,"/",i2 )' &
       ) year,month,day
  print *,"Long date:",longdate
  !!codesnippet end
  print *,"slash"

end Program ReadWrite
