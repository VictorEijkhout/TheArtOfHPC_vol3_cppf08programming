!****************************************************************
!****
!**** This file belongs with the course
!**** Introduction to Scientific Programming in C++/Fortran2003
!**** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!****
!**** equiprime.F90 : Fortran for a special case of the goldbach conjecture
!****
!****************************************************************

Module Primes
  Type Generator
     integer :: numberfound = 0
     integer :: currentprime = 2
   contains
     procedure,public :: FirstPrime,NextPrime,Reset
     procedure,public :: Currently ! only for testing
  End type Generator

contains

  integer function Currently(p)
    implicit none
    class(Generator) :: p
    Currently = p%currentprime
  end function Currently

  logical function IsPrime(number)
    implicit none
    integer,intent(in) :: number
    ! local variables
    integer :: divisor
    do divisor=2,number-1
       if (mod(number,divisor)==0) then
          IsPrime = .False. ; return
       end if
    end do
    IsPrime = .True.
  end function IsPrime

  ! Primality testing
  ! Restart a sequence
  subroutine Reset(p)
    implicit none
    class(Generator) :: p
    p%currentprime = 1
  end subroutine Reset
  ! Return the first prime
  integer function FirstPrime(p)
    implicit none
    class(Generator) :: p

    call p%Reset()
    FirstPrime = p%NextPrime()
  end function FirstPrime
  ! Return the next prime
  integer function NextPrime(p)
    implicit none
    class(Generator) :: p
    ! local
    integer :: cur
    do 
       p%currentprime = p%currentprime+1
       if (IsPrime(p%currentprime)) then
          NextPrime = p%currentprime
          exit
       end if
    end do
  end function NextPrime
  
end Module Primes

Program EquiPrime

  use Primes

  implicit none

  type(Generator) :: primes1,primes2
  integer :: p,q,t
  logical :: confirm

  call primes1%Reset()
  do
     p = primes1%NextPrime()
     if (p>5000) exit
     confirm = .false.
     call primes2%Reset()
     do
        q = primes2%NextPrime()
        if (q>p) then
           print *,"Conjecture falsified"
           stop
        end if
        t = p+(p-q)
        if (IsPrime(t)) then
           print *,p,"equidistant between",q,t
           confirm = .true.
           exit
        end if
     end do
  end do
  
End Program EquiPrime
