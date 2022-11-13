!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** listf.F90 : linked list basics in Fortran
!***
!****************************************************************

Program LinkedList

  implicit none

  !!codesnippet linklistftypes
  type node
     integer :: value
     type(node),pointer :: next
  end type node

  type list
     type(node),pointer :: head
  end type list
  !!codesnippet end
  
  !!codesnippet linklistfmain
  integer,parameter :: listsize=7
  type(list) :: the_list
  integer,dimension(listsize) :: inputs = &
       [ 62, 75, 51, 12, 14, 15, 16 ]
  integer :: in,in_value

  nullify(the_list%head)
  do in=1,listsize
     in_value = inputs(in)
     call insert(the_list,in_value)
     call print(the_list)
  end do
  !!codesnippet end

contains
  
  subroutine insert( the_list,value )
    implicit none
    ! parameters
    type(list),intent(inout) :: the_list
    integer,intent(in) :: value
    ! local
    type(node),pointer :: current,new_node

    if (.not.associated(the_list%head)) then
       ! case: empty list
       allocate(new_node); new_node%value = value; nullify(new_node%next);
       the_list%head => new_node
    else if (value<the_list%head%value) then
       ! case: before list head
       allocate(new_node)
       new_node%value = value; new_node%next => the_list%head
       the_list%head => new_node
    else 
       ! case somewhere in the list
       current => the_list%head
       do
          if ( value > current%value ) then
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
          allocate(new_node); new_node%value = value
          nullify(new_node%next)
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
          write(*,'(i3,1x)',advance="no") current%value
          if (.not.associated(current%next)) exit
          current => current%next
       end do
    end if
    write(*,'(x"]")')

  end subroutine print
  
end Program LinkedList
