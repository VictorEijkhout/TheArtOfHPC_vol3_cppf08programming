!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** contact.F90 : disease propagation through random contact
!***
!****************************************************************

Program Contact
  implicit none

  integer :: pop_size,connectivity
  integer,dimension(:,:),allocatable :: contacts
  integer,dimension(:,:),allocatable :: infected
  ! local
  integer :: giver,receiver,connect,day
  real(4) :: fraction

  print *,"Population size:"
  read *,pop_size
  print *,"Number of contacts per person:"
  read *,connectivity
  if (connectivity<1) &
       connectivity = 2
  allocate(contacts(pop_size,pop_size),infected(pop_size,pop_size))
  contacts = 0; infected = 0;
  
  !
  ! Set up the contacts matrix; each person transmits to only one other
  do giver=1,pop_size
     do connect=1,connectivity
        call random_number(fraction)
        receiver = 1+pop_size*fraction
        contacts(receiver,giver) = 1
     end do
  end do

  call random_number(fraction)
  giver = 1+pop_size*fraction

  infected(giver,1) = 1
  do day=2,pop_size
     infected(:,day) = matmul(contacts,infected(:,day-1))
     where ( infected(:,day)>0 ) &
          infected(:,day) = 1
     print '(a6,1x,i2,1x,a12,100i4)',"On day",day,", infection:",infected(:,day)
  end do
  
End Program Contact
