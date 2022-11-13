!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** block.F90 : do/slice/forall/concurrent assignment
!***
!****************************************************************


Program CopySlice

  implicit none

  integer,parameter :: n = 10
  integer, dimension(n) :: counting,counted
  integer :: i

  !!
  !! Sequential gives a recurrence
  !!
  forall (i=1:n)
     counting(i) = i
     counted(i) = 0
  end forall
  print 10,"Original  ",counting

  !!codesnippet blockrecur
  do i=2,n
     counted(i) = 2*counting(i-1)
  end do
  !!codesnippet end
  print 11,"Recursive ",counted

  !!
  !! Forall is concurrent
  !!
  forall (i=1:n)
     counting(i) = i
     counted(i) = 0
  end forall
  print 10,"Original  ",counting

  !!codesnippet blockslice
  counted(2:n) = 2*counting(1:n-1)
  !!codesnippet end
  print 11,"Sliced    ",counted

  !!
  !! Forall is also concurrent
  !!
  forall (i=1:n)
     counting(i) = i
     counted(i) = 0
  end forall
  print 10,"Original  ",counting

  !!codesnippet blockforall
  forall (i=2:n)
     counted(i) = 2*counting(i-1)
  end forall
  !!codesnippet end
  print 11,"Forall    ",counted

  !!
  !! Concurrent is also concurrent
  !!
  forall (i=1:n)
     counting(i) = i
     counted(i) = 0
  end forall
  print 10,"Original  ",counting

  !!codesnippet blockconc
  do concurrent (i=2:n)
     counted(i) = 2*counting(i-1)
  end do
  !!codesnippet end
  print 11,"Concurrent",counted

10 format(a10,10i4)
11 format(a10,10i4,//)

end Program CopySlice

