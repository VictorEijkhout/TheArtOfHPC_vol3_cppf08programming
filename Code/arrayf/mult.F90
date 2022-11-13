!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** mult.F90 : multiplying matrices
!***
!****************************************************************

Program Mult
  implicit none

  integer,parameter :: N=1000
  real(8),dimension(N,N) :: A,B,C,Reference
  real(8) :: acc
  integer :: i,j,k

  !!codesnippet fclock
  integer :: clockrate,clock_start,clock_end
  call system_clock(count_rate=clockrate)
  !!codesnippet end
  print *,"Clock resolution:",clockrate

  ! Initialize the matrix
  call random_number(A)
  call random_number(B)

  !!codesnippet fclock
  call system_clock(clock_start)
  !!codesnippet end
  do i=1,N
     do j=1,N
        acc = 0
        do k=1,N
           acc = acc + A(i,k)*B(k,j)
        end do
        Reference(i,j) = acc
     end do
  end do
  !!codesnippet fclock
  call system_clock(clock_end)
  print *,"time:",(clock_end-clock_start)/REAL(clockrate)
  !!codesnippet end

  call system_clock(clock_start)
  do i=1,N
     do j=1,N
        C(i,j) = DOT_PRODUCT( A(i,:),B(:,j) )
     end do
  end do
  call system_clock(clock_end)
  print *,"Inner product:",(clock_end-clock_start)/REAL(clockrate)
  print 10,MAXVAL( ABS( C-Reference ) )

  call system_clock(clock_start)
  C = MATMUL(A,B)
  call system_clock(clock_end)
  print *,"Matmul:",(clock_end-clock_start)/REAL(clockrate)
  print 10,MAXVAL( ABS( C-Reference ) )

  C = 0
  call system_clock(clock_start)
  do j=1,N
     do k=1,N
        C(:,j) = C(:,j) + A(:,k) * B(k,j)
     end do
  end do
  call system_clock(clock_end)
  print *,"Columns:",(clock_end-clock_start)/REAL(clockrate)
  print 10,MAXVAL( ABS( C-Reference ) )

  C = 0
  call system_clock(clock_start)
  do i=1,N
     do k=1,N
        C(i,:) = C(i,:) + A(i,k) * B(k,:)
     end do
  end do
  call system_clock(clock_end)
  print *,"Rows:",(clock_end-clock_start)/REAL(clockrate)
  print 10,MAXVAL( ABS( C-Reference ) )

  C = 0
  call system_clock(clock_start)
  do i=1,N
     do k=1,N
        do j=1,N
           C(i,j) = C(i,j) + A(i,k) * B(k,j)
        end do
     end do
  end do
  call system_clock(clock_end)
  print *,"Rows, elt:",(clock_end-clock_start)/REAL(clockrate)
  print 10,MAXVAL( ABS( C-Reference ) )

10 FORMAT( x,3H  (,"error:",x,e12.6,1H) )

End Program Mult
