#include <iostream>
#include <vector>

#if defined(__GLIBC__) && ((__GLIBC__>=2 && __GLIBC_MINOR__ >= 8) || __GLIBC__>2) \
 && defined(__LP64__)
  #define GLIBC_MALLOC_ALREADY_ALIGNED 1
#else
  #define GLIBC_MALLOC_ALREADY_ALIGNED 0
#endif

#if defined(__FreeBSD__) && !defined(__arm__) && !defined(__mips__)
  #define FREEBSD_MALLOC_ALREADY_ALIGNED 1
#else
  #define FREEBSD_MALLOC_ALREADY_ALIGNED 0
#endif

#if (defined(__APPLE__) \
 || defined(_WIN64) \
 || GLIBC_MALLOC_ALREADY_ALIGNED \
 || FREEBSD_MALLOC_ALREADY_ALIGNED)
  #define MALLOC_ALREADY_ALIGNED 1
#else
  #define MALLOC_ALREADY_ALIGNED 0
#endif

#if ((defined __QNXNTO__) || (defined _GNU_SOURCE) || ((defined _XOPEN_SOURCE) && (_XOPEN_SOURCE >= 600))) \
 && (defined _POSIX_ADVISORY_INFO) && (_POSIX_ADVISORY_INFO > 0)
  #define HAS_POSIX_MEMALIGN 1
#else
  #define HAS_POSIX_MEMALIGN 0
#endif

#if SSE_INSTR_SET > 0
    #define HAS_MM_MALLOC 1
#else
    #define HAS_MM_MALLOC 0
#endif


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

namespace detail
{
  inline void* _aligned_malloc(size_t size, size_t alignment)
  {
    void* res = 0;
    void* ptr = malloc(size+alignment);
    if(ptr != 0)
      {
	res = reinterpret_cast<void*>((reinterpret_cast<size_t>(ptr) & ~(size_t(alignment-1))) + alignment);
	*(reinterpret_cast<void**>(res) - 1) = ptr;
      }
    return res;
  }
}

inline void* aligned_malloc(size_t size, size_t alignment)
{
#if MALLOC_ALREADY_ALIGNED
  return malloc(size);
#elif HAS_MM_MALLOC
  return _mm_malloc(size,alignment);
#elif HAS_POSIX_MEMALIGN
  void* res;
  const int failed = posix_memalign(&res,size,alignment);
  if(failed) res = 0;
  return res;
#elif (defined _MSC_VER)
  return _aligned_malloc(size, alignment);
#else
  return detail::_aligned_malloc(size,alignment);
#endif
}

namespace detail
{
  inline void _aligned_free(void* ptr)
  {
    if(ptr != 0)
      free(*(reinterpret_cast<void**>(ptr)-1));
  }
}

inline void aligned_free(void* ptr)
{
#if MALLOC_ALREADY_ALIGNED
  free(ptr);
#elif HAS_MM_MALLOC
  _mm_free(ptr);
#elif HAS_POSIX_MEMALIGN
  free(ptr);
#elif defined(_MSC_VER)
  _aligned_free(ptr);
#else
  detail::_aligned_free(ptr);
#endif
}

template <class T, int N>
typename aligned_allocator<T,N>::pointer
aligned_allocator<T,N>::allocate(size_type n, typename std::allocator<T>::const_pointer hint)
{
  pointer res = reinterpret_cast<pointer>(aligned_malloc(sizeof(T)*n,N));
  if(res == 0)
    throw std::bad_alloc();
  return res;
}

template <class T, int N>
void // VLE ??? typename aligned_allocator<T,N>::pointer
aligned_allocator<T,N>::deallocate(pointer p, size_type t)
{
  aligned_free(p);
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
    std::cout << "Successful alignment at 64\n";
  else
    std::cout << "alignment trouble: " << v1addr << "=/=" << v1align << '\n'; 

  // // code filling v1 and v2
  // for(size_t i = 0; i < v1.size(); i += simd_traits<double>::size)
  //   {
  //     vector2d v1d = load_a(&v1[i]);
  //     vector2d v2d = load_a(&v2[i]);
  //     vector2d v3d = v1d + v2d;
  //     store_a(&v3[i],v3d);
  //   }

  return 0;
}
