!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** where.F90 : using the WHERE and ALL statement
!***
!****************************************************************

Program Norms
  implicit none
  integer,parameter :: N=7
  real(8),dimension(N,N) :: A,B,Abig,Asmall,Aerror
  integer,dimension(N,N) :: Ai,Bi
  integer :: i,j

  ! Initialize the matrix
  call random_number(A)

  Where (A>.5)
     Abig = A
     Asmall = 0
     B = 1.
  Elsewhere
     Abig = 0.
     Asmall = A
     B = 0.
  end Where

  print 10,"Matrix:",( ( A(i,j),j=1,n ),i=1,n )
  print 10,"Nixed: ",( ( B(i,j),j=1,n ),i=1,n )

  print 10,"Large: ",( ( Abig(i,j),j=1,n ),i=1,n )
  print 10,"Small: ",( ( Asmall(i,j),j=1,n ),i=1,n )

  Aerror = A-(Abig+Asmall)
  print *,size(Aerror),ALL( abs(Aerror)<1.e-10 )

10 format(a10,/,7( 7(f7.4,1x),/) )
20 format(a10,/,7(f7.4,1x))

  Bi = int(B)  
  print 30,"Convert:",( ( Bi(i,j),j=1,n ),i=1,n )
30 format(a10,/,7( 7(i2,1x),/) )


End Program Norms
