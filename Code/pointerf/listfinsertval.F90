!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** listf.F90 : linked list basics in Fortran
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
  integer,dimension(7) :: inputs = [ 62, 75, 51, 12, 14, 15, 16 ]

  nullify(the_list%head)

  !!codesnippet linklistfinsert
  allocate(node_ptr); node_ptr%value = 1
  call insert(the_list,node_ptr)
  allocate(node_ptr); node_ptr%value = 5
  call insert(the_list,node_ptr)
  allocate(node_ptr); node_ptr%value = 3
  call insert(the_list,node_ptr)

  call print(the_list)
  !!codesnippet end

contains
  
  subroutine insert( the_list,new_node )
    implicit none
    ! parameters
    type(list),intent(inout) :: the_list
    type(node),intent(inout),pointer :: new_node
    ! local
    type(node),pointer :: current,previous

    if (.not.associated(the_list%head)) then
       ! case: empty list
       the_list%head => new_node
    else if (new_node%value<the_list%head%value) then
       ! case: before list head
       new_node%next => the_list%head
       the_list%head => new_node
    else 
       ! case somewhere in the list
       current => the_list%head
       do
          if ( new_node%value > current%value ) then
             if ( associated(current%next) ) then
                ! case: between current and next
                if ( value<current%next%value ) &
                     exit
             else
                ! case: current is end of the list
                exit
             end if
          end if
          current => current%next
       end do

       if (current%value==value) then
          return
       else if (.not.associated(current%next)) then
          current%next => new_node
       else if (value<current%next%value) then
          allocate(new_node); new_node%value = value
          new_node%next => current%next
          current%next => new_node
       end if
    end if
    
  end subroutine insert
  
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
