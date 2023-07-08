/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pmr.cxx : allocation of through polymorphic resources
 ****
 ****************************************************************/

#include <memory_resource>

template< int A >
class aligned_resource : public std::pmr::memory_resource {
public:
  explicit aligned_resource
  ( std::pmr::memory_resource *parent = std::pmr::get_default_resource() ) {
    m_parent = parent; };
  ~aligned_resource();
  std::pmr::memory_resource *parent() const;
protected:
  void *do_allocate( size_t bytes, size_t alignment ) override {
    void *ret = m_parent->allocate(bytes,alignment);
    // here you could keep track of how many bytes allocated
    return ret;
  };
  void do_deallocate( void *p, size_t bytes, size_t alignment ) override {
    m_parent->deallocate( p,bytes,alignment );
  };
  bool do_is_equal( const std::pmr::memory_resource &other )
    const noexcept override { return true; };
private:
  struct allocation_record {
    void *m_ptr; size_t m_bytes; size_t m_alignment; };
  std::pmr::memory_resource *m_parent;
};

template< typename T, int A >
class aligned_allocator : public std::pmr::polymorphic_allocator<T> {
public:
  aligned_allocator() = delete;
  aligned_allocator( std::pmr::memory_resource* r )
    : std::pmr::polymorphic_allocator<T>(r) {};
};

template< typename T, int A >
class aligned_vector : public std::vector<T,aligned_allocator<T,A>> {
};

int main() {
  aligned_vector<double,64> v64;
  return 0;
};
