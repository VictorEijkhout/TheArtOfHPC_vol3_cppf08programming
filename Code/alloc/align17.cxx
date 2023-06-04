/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraynew.cxx : allocation of arrays through new
 ****
 **** I DON'T KNOW WHERE I GOT THIS.
 **** it aborts with a bad_alloc exception
 ****
 ****************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib> // VLE for aligned_malloc

template <class T, int N>
class aligned_allocator
{

public:

  typedef T value_type;
  typedef T& reference;
  typedef const T& const_reference;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  template <class U>
  struct rebind
  {
    typedef aligned_allocator<U,N> other;
  };

  inline aligned_allocator() throw() {}
  inline aligned_allocator(const aligned_allocator&) throw() {}

  template <class U>
  inline aligned_allocator(const aligned_allocator<U,N>&) throw() {}

  inline ~aligned_allocator() throw() {}

  inline pointer address(reference r) { return &r; }
  inline const_pointer address(const_reference r) const { return &r; }

  pointer allocate(size_type n, typename std::allocator<T>::const_pointer hint = 0);
  inline void deallocate(pointer p, size_type);

  inline void construct(pointer p, const_reference value) { new (p) value_type(value); }
  inline void destroy(pointer p) { p->~value_type(); }

  inline size_type max_size() const throw() { return size_type(-1) / sizeof(T); }

  inline bool operator==(const aligned_allocator&) { return true; }
  inline bool operator!=(const aligned_allocator& rhs) { return !operator==(rhs); }
};

// VLE using:
// void* aligned_alloc( std::size_t alignment, std::size_t size ); (since C++17)
// https://en.cppreference.com/w/cpp/memory/c/aligned_alloc

template <class T, int N>
typename aligned_allocator<T,N>::pointer
aligned_allocator<T,N>::allocate(size_type n, typename std::allocator<T>::const_pointer hint)
{
  pointer res = reinterpret_cast<pointer>(aligned_alloc(N,sizeof(T)*n)); // VLE (sizeof(T)*n,N));
  if(res == 0)
    throw std::bad_alloc();
  return res;
}

template <class T, int N>
void // VLE ??? typename aligned_allocator<T,N>::pointer
aligned_allocator<T,N>::deallocate(pointer p, size_type t)
{
  std::free(p); // VLE aligned_free(p);
}

int main() {

  typedef std::vector<double,aligned_allocator<double,64> > vector_type;
  vector_type v1(5,1),v2(5),v3;
  v2.at(0) = v1.at(1);
  std::cout << v2[0] << '\n';

  double *v1data = v1.data();
  long int v1addr,v1align;
  v1addr = reinterpret_cast<long int>(v1data);
  v1align = (v1addr>>5)<<5;
  if (v1addr==v1align)
    std::cout << "Successful alignment\n";
  else
    std::cout << "alignment trouble: " << v1addr << "=/=" << v1align << '\n'; 

  return 0;
}
