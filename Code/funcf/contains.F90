Program ContainsScope
  implicit none
  integer :: i

  call DoWhat()

Contains
  subroutine DoWhat()
    implicit none
    print *,i
  end subroutine DoWhat

end Program ContainsScope

  
