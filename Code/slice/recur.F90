!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** recur.F90 : the trouble with recursions
!***
!****************************************************************


Program RecurSlice

  implicit none

  integer,parameter :: n = 10
  integer, dimension(n) :: counting
  integer :: i

  !!
  !! Sequential gives a recurrence
  !!
  forall (i=1:n)
     counting(i) = i
  end forall
  print 10,"Original  ",counting

  !!codesnippet slicerecur
  do i=2,n
     counting(i) = 2*counting(i-1)
  end do
  !!codesnippet end
  print 11,"Recursive ",counting

  !!
  !! Forall is concurrent
  !!
  forall (i=1:n)
     counting(i) = i
  end forall
  print 10,"Original  ",counting

  !!codesnippet sliceslice
  counting(2:n) = 2*counting(1:n-1)
  !!codesnippet end
  print 11,"Sliced    ",counting

  !!
  !! Forall is also concurrent
  !!
  forall (i=1:n)
     counting(i) = i
  end forall
  print 10,"Original  ",counting

  !!codesnippet sliceforall
  forall (i=2:n)
     counting(i) = 2*counting(i-1)
  end forall
  !!codesnippet end
  print 11,"Forall    ",counting

  !!
  !! Concurrent is also concurrent
  !!
  forall (i=1:n)
     counting(i) = i
  end forall
  print 10,"Original  ",counting

  !!codesnippet sliceconc
  do concurrent (i=2:n)
     counting(i) = 2*counting(i-1)
  end do
  !!codesnippet end
  print 11,"Concurrent",counting

10 format(a10,10i4)
11 format(a10,10i4,//)

end Program RecurSlice

