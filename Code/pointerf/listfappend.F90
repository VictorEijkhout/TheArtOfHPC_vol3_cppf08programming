!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** listf.F90 : linked list basics in Fortran
!***
!*** THIS IS NOT THE RIGHT WAY TO DO IT, SEE listfappendallocat INSTEAD
!***
!****************************************************************

Program LinkedList

  implicit none

  type node
     integer :: value
     type(node),pointer :: next
  end type node

  type list
     type(node),pointer :: head
  end type list
  
  type(list) :: the_list
  type(node),pointer :: node_ptr

  nullify(the_list%head)

  allocate(node_ptr); node_ptr%value = 1
  call attach(the_list,node_ptr)
  allocate(node_ptr); node_ptr%value = 5
  call attach(the_list,node_ptr)
  allocate(node_ptr); node_ptr%value = 3
  call attach(the_list,node_ptr)

  call print(the_list)

contains
  
  subroutine attach( the_list,new_node )
    implicit none
    ! parameters
    type(list),intent(inout) :: the_list
    type(node),intent(inout),pointer :: new_node

    ! local
    integer :: value
    type(node),pointer :: current,previous

    ! if the list has no head node, attached the new node
    if (.not.associated(the_list%head)) then
       nullify(new_node%next)
       the_list%head => new_node
    else
       ! go down the list, finding the last node
       current => the_list%head
       do while ( associated(current%next) )
          previous => current
          current => current%next
       end do
       nullify(new_node%next)
       current%next => new_node
    end if
    
  end subroutine attach
  
  integer function length( the_list )
    implicit none
    type(list),intent(in) :: the_list
    ! local
    type(node),pointer :: current

    if (.not.associated(the_list%head)) then
       length = 0
    else
       current => the_list%head       
       do
          length = length+1
          if (.not.associated(current%next)) exit
          current => current%next
       end do
    end if

  end function length

  subroutine print(the_list)
    implicit none
    type(list),intent(in) :: the_list
    type(node),pointer :: current

    write(*,'("List: [ ")',advance="no")
    if (associated(the_list%head)) then
       current => the_list%head
       do while (associated(current))
          write(*,'(i1",")',advance="no") current%value
          if (.not.associated(current%next)) exit
          current => current%next
       end do
    end if
    write(*,'(x"]")')

  end subroutine print
  
end Program LinkedList
