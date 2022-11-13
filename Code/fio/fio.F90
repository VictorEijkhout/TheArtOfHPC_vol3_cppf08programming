!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** fio.cxx : Fortran I/O
!***
!****************************************************************

Program FortranIO

  integer,parameter :: dim=10
  real(4),dimension(dim,dim) :: array
  integer :: i,j

  do i=1,dim
     do j=1,dim
        array(i,j) = i+1./(j+1)
     end do
  end do
  
  print '(10(10(f6.3,1x),//))',( (array(i,j),j=1,dim), i=1,dim )

end Program FortranIO
