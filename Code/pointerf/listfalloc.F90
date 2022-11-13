!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** listf.F90 : linked list basics in Fortran
!***
!****************************************************************


Program LinkedList

  implicit none

  !!codesnippet linklistf
  type node
     integer :: value
     type(node),pointer :: next
  end type node

  type list
     type(node),pointer :: head
  end type list
  
  type(list) :: the_list
  nullify(the_list%head)
  !!codesnippet end
  
  call attach(the_list,1)

  call attach(the_list,5)

  call attach(the_list,3)
  call print(the_list)

contains
  
  subroutine attach( the_list,value )
    implicit none
    ! parameters
    type(list),intent(inout) :: the_list
    integer,intent(in) :: value
    ! local
    type(node),pointer :: current,previous,new_node

    nullify(new_node)
    if (.not.associated(the_list%head)) then
       !!codesnippet listheadf
       allocate(new_node)
       new_node%value = value
       nullify(new_node%next)
       the_list%head => new_node
       !!codesnippet end
    else

       current => the_list%head ; nullify(previous)
       do while ( current%value<value &
            .and. associated(current%next) )
          previous => current
          current => current%next
       end do

       if (current%value==value) then
          return
       else if (value<current%value) then
          !!codesnippet listinsertfalloc
          allocate(new_node)
          new_node%value = value
          new_node%next => current
          previous%next => new_node
          !!codesnippet end
       else if (.not.associated(current%next)) then
          allocate(new_node)
          new_node%value = value
          nullify(new_node%next)
          current%next => new_node
       end if
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
