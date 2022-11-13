Program size

  implicit none

  !!codesnippet fstorage
  real(4) :: r4
  real(8) :: r8
  real(16) :: r16
  !!codesnippet end

  print *,"real(4) takes:",storage_size(r4)
  print *,"real(8) takes:",storage_size(r8)
  print *,"real(16) takes:",storage_size(r16)
  
end Program size
