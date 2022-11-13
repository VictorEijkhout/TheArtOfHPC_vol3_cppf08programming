!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** quotes.F90 : illustration of text stuff
!***
!****************************************************************

Program Quotes
  implicit none

  !!codesnippet fstrlen
  character(len=12) :: strvar
  !!codesnippet end

  !!codesnippet fconcat
  character(len=10) :: firstname,lastname
  character(len=15) :: shortname,fullname
  !!codesnippet end

  print *,"Quote:"
  !!codesnippet fquotes
  print *,'This string was in single quotes'
  print *,'This string in single quotes contains a single '' quote'
  print *,"This string was in double quotes"
  print *,"This string in double quotes contains a double "" quote"
  !!codesnippet end
  print *,"--quote."

  print *,"Concat:"
  !!codesnippet fconcat
  firstname = "Victor"; lastname = "Eijkhout"
  shortname = firstname // lastname
  print *,"without trimming: ",shortname
  fullname = trim(firstname) // " " // trim(lastname)
  print *,"with trimming: ",fullname
  !!codesnippet end
  print *,"--concat."

  print *,"Strlen:"
  !!codesnippet fstrlen
  strvar = "word"
  print *,len(strvar),len(trim(strvar))
  !!codesnippet end
  print *,"--strlen."


end Program Quotes
