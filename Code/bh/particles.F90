!****************************************************************
!***
!*** This file belongs with the course
!*** Introduction to Scientific Programming in C++/Fortran2003
!*** copyright 2021 Victor Eijkhout eijkhout@tacc.utexas.edu
!***
!*** particles.F90 : center of mass stuff
!***
!****************************************************************

Module Particles

  Type Force
     real :: fx,fy
   contains
     procedure,public :: add_forces
  End type Force

  Type Particle
     real :: x,y,charge
   contains
     procedure,public :: random,read,force_from
  End type Particle

  Type Cloud
     Type(Particle),dimension(:),allocatable :: particles
   contains
     procedure,public :: allocate,cloudsize,readall
  End type Cloud

  interface operator(+)
     module procedure add_forces
  end interface operator(+)

contains

  !!
  !! Force methods
  !!
  Function add_forces(f1,f2) result(f3)
    implicit none
    Class(Force),Intent(In) :: f1,f2
    Type(Force) :: f3
    f3%fx = f1%fx + f2%fx
    f3%fy = f1%fy + f2%fy
  End Function add_forces

  !!
  !! Particle methods
  !!
  Subroutine random(p)
    implicit none
    Class(Particle),Intent(Out) :: p
    call random_number(p%x)
    call random_number(p%y)
    call random_number(p%charge)
  End Subroutine random

  Subroutine read(p)
    implicit none
    Class(Particle),Intent(Out) :: p
    read *,p%x,p%y,p%charge
  End Subroutine read

  Function force_from( p,q ) result(f)
    implicit none
    Class(Particle),Intent(In) :: p,q
    Type(Force) :: f
    real :: magnitude,dx,dy, vector_length, dsquared

    ! unit vector from q to p
    dx = p%x - q%x ; dy = p%y - q%y
    dsquared = dx**2 + dy**2
    vector_length = sqrt( dsquared )
    dx = dx/vector_length; dy = dy/vector_length

    ! force magnitude
    magnitude = p%charge * q%charge / dsquared

    f%fx = magnitude * dx ; f%fy = magnitude * dy
  End Function force_from

  !!
  !! Cloud methods
  !!
  Integer Function cloudsize(c)
    implicit none
    Class(Cloud),Intent(In) :: c
    cloudsize = size(c%particles)
  End Function cloudsize

  Subroutine allocate(c,n)
    implicit none
    Class(Cloud),Intent(InOut) :: c
    Integer,Intent(In) :: n
    allocate(c%particles(n))
  End Subroutine allocate

  Subroutine readall(c)
    implicit none
    Class(Cloud),Intent(InOut) :: c
    Integer :: i
    do i=1,c%cloudsize()
       call c%particles(i)%read()
    end do
  End Subroutine readall

end Module Particles

Program Simulation
  Use Particles
  implicit none

  Integer :: nparticles
  Type(Particle) :: test_particle
  Type(Cloud) :: my_particles

  call test_particle%random()
  print *,"Random",test_particle%x,test_particle%y,test_particle%charge

  call test_particle%read()
  print *,"Read one:",test_particle%x,test_particle%y,test_particle%charge
  
  Read *,nparticles
  call my_particles%allocate(nparticles)
  Print *,"Making cloud, size is:",my_particles%cloudsize()
  call my_particles%readall()

  call force_test()

contains
  subroutine force_test()
    implicit none
    Type(Particle) :: p0,p1,p2
    Type(Force) :: f01,f02,fsum
    p0 = Particle(0.,0.,1.)
    p1 = Particle(1.,1.,1.)
    p2 = Particle(2.,2.,1.)
    f01 = p0%force_from(p1)
    f02 = p0%force_from(p2)
    print *,f01
    print *,f02
    fsum = f01+f02
    print *,fsum
  end subroutine force_test

End Program Simulation
