!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** lapack.F90 : a linear algebra package
!***
!****************************************************************

Module LAPack
contains

  logical function Equals(A,B)
    implicit none
    real(8),dimension(:,:),intent(in) :: A,B
    ! local
    integer :: m,n, i,j

    m = size(A,1); n = size(A,2)
    Equals = .true.
    do i=1,m
       do j=1,n
          if ( abs(A(i,j)-B(i,j))*1.d-14>max(abs(A(i,j)),abs(B(i,j))) ) then
             Equals = .false.
             return
          end if
       end do
    end do
  end function Equals
  
  subroutine Identity(A)
    implicit none
    real(8),dimension(:,:),intent(out) :: A
    ! local
    call Diagonal(A,1.d0)
  end subroutine Identity
  
  subroutine Diagonal(A,v)
    implicit none
    real(8),dimension(:,:),intent(out) :: A
    real(8),intent(in) :: v
    ! local
    integer :: i

    A = 0.d0
    do i=1,size(A,1)
       A(i,i) = v
    end do
  end subroutine Diagonal

  subroutine TriDiagonal(A,v1,v2,v3)
    implicit none
    real(8),dimension(:,:),intent(out) :: A
    real(8),intent(in) :: v1,v2,v3
    ! local
    integer :: i

    A = 0.d0
    do i=1,size(A,1)
       A(i,i) = v2
    end do
    do i=1,size(A,1)-1
       A(i+1,i) = v1
       A(i,i+1) = v3
    end do
  end subroutine TriDiagonal

  subroutine Mult(A,B,C)
    implicit none
    real(8),dimension(:,:),intent(in) :: A,B
    real(8),dimension(:,:),intent(out) :: C
    ! local
    integer :: i,j,k, n
    real(8),dimension(:),allocatable,save :: tmp

    n = size(A,1)
    if (.not.allocated(tmp)) allocate(tmp(n))

    if (.not. (n==size(A,2) .and. n==size(B,1) .and. n==size(B,2)) ) &
         stop "Need square matrices"
    do i=1,n
       do j=1,n
          tmp = A(i,:)*B(:,j)
          C(i,j) = product(tmp)
       end do
    end do
  end subroutine Mult

  integer function Bandwidth(A)
    implicit none
    real(8),dimension(:,:),intent(in) :: A
    !
    integer :: i,m,n,b

    m = size(A,1); n = size(A,2)
    do i=1,m
       b = 0
       do while (A(i,i+b)/=0 .and. i+b<n)
          b = b+1
       end do
       if (b>Bandwidth) Bandwidth = b
       b = 0
       do while (A(i,i-b)/=0 .and. i-b>1)
          b = b-1
       end do
       if (b>Bandwidth) Bandwidth = b
    end do
  end function Bandwidth
  
End Module LAPack

Program LATest
  use LAPack
  implicit none
  integer :: size

  real(8),dimension(:,:),allocatable :: A,B,C
  read *,size
  allocate(A(size,size),B(size,size),C(size,size))

  call Identity(A)
  print *,"Missing Laplace call" !!!! call Laplace(B)
  call Mult(A,B,C)
  print *,"B should be C:",Equals(B,C)

  call TriDiagonal(A,-1.d0,2.d0,-1.d0)
  call TriDiagonal(B,-1.d0,2.d0,-1.d0)
  call Mult(A,B,C)
  print *,"Bandwidth is 5:",Bandwidth(C)

End Program LATest
