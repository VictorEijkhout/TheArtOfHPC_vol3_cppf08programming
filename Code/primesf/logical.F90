!################################################################
!####
!#### student program with strange behavior
!#### note that the function is never assigned
!#### different behavior with opt 0 or 2
!####
!################################################################

program primes
  implicit none
  integer :: how_many, i
  ! read*, how_many
  !do i =2, how_many
  do i = 2, 20
     if(is_prime(i)) then
        print *,"prime:",i
     else
        print *,"not:",i
     end if
  end do
contains
  logical function is_prime (limit)
    implicit none
    integer :: limit, i
    logical :: found
    found = .true.
    do i = 2, limit/2
       if( MOD(limit,i) == 0) then
          found = .true.
          exit
       end if
    end do
    return
  end function is_prime

end program primes
