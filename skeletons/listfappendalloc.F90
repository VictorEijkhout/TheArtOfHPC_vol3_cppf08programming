!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** listfappendalloc.F90 : append only
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
  
  integer,parameter :: listsize=7
  type(list) :: the_list
  integer,dimension(listsize) :: inputs = &
       [ 62, 75, 51, 12, 14, 15, 16 ]
  integer :: input,input_value

  nullify(the_list%head)
  do input=1,listsize
     input_value = inputs(input)
     call attach(the_list,input_value)
  end do

  call print(the_list)

contains
  
  subroutine attach( the_list,new_value )
    implicit none
    ! parameters
    type(list),intent(inout) :: the_list
    integer,intent(in) :: new_value

    ! local

    ! if the list has no head node, attached the new node
    if (.not.associated(the_list%head)) then
       allocate( the_list%head )
       the_list%head%value = new_value
    else
       call node_attach( the_list%head,new_value )
    end if

#if 0
#endif
    
  end subroutine attach
  
  recursive subroutine node_attach( the_node,new_value )
    implicit none
    ! parameters
    type(node),intent(inout) :: the_node
    integer,intent(in) :: new_value
    
    if ( .not. associated(the_node%next) ) then
       allocate( the_node%next )
       the_node%next%value = new_value
    else
       call node_attach( the_node%next,new_value )
    end if

  end subroutine node_attach

  integer function length( the_list )
    implicit none
    type(list),intent(in) :: the_list
    ! local
    type(node),pointer :: current

  end function length

  subroutine print(the_list)
    implicit none
    type(list),intent(in) :: the_list
    type(node),pointer :: current

    write(*,'("List: [ ")',advance="no")
    if (associated(the_list%head)) then
       current => the_list%head
       do while (associated(current))
          write(*,'(i0",")',advance="no") current%value
          if (.not.associated(current%next)) exit
          current => current%next
       end do
    end if
    write(*,'(x"]")')

  end subroutine print
  
end Program LinkedList
