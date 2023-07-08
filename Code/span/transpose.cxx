/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** transpose.cxx : square matrix transpose
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <execution>
#include <tuple>
using std::tuple;
#include <vector>
using std::vector;

//#include <ranges>
#include <range/v3/all.hpp>
#ifdef RANGES_V3_ALL_HPP
namespace rng = ranges;
#else
namespace rng = std::ranges;
#endif

//codesnippet mdspankokkos
#include "mdspan/mdspan.hpp"
namespace md = Kokkos;
namespace KokkosEx = MDSPAN_IMPL_STANDARD_NAMESPACE::MDSPAN_IMPL_PROPOSED_NAMESPACE;
namespace mdx = KokkosEx;
//codesnippet end

int main() {
  constexpr int Nhalf=5, N=2*Nhalf;
  //codesnippet mdspan2d
  vector<float> A(N*N),B(N*N);
  //codesnippet end
  for ( int count=1; auto& e : A )
    e = count++;
  
  //codesnippet mdspan2d
  md::mdspan Amd{ A.data(),N,N };
  md::mdspan Bmd{ B.data(),N,N };
  //codesnippet end

  cout << Amd.extent(0) << " x " << Amd.extent(1) << '\n';
  //codesnippet mdspan2cart
  auto Aij = rng::views::cartesian_product
    ( rng::iota_view(0,N), // Amd.extent(0)), argument deduction fails
      rng::iota_view(0,N) // Amd.extent(1));
      );
  //codesnippet end

  //codesnippet mdspan2ij
  std::for_each
    ( std::execution::par_unseq,
      Aij.begin(),Aij.end(),
      [&] ( auto idx ) {
	auto [i,j] = idx;
	B[j,i] = A[i,j];
      }
      );
  //codesnippet end

  // NOPE  mdx::submdspan A_TL( Amd, {0,Nhalf},{0,Nhalf} );
  auto A_TL = mdx::submdspan( Amd, tuple{0,Nhalf},tuple{0,Nhalf} );
  auto A_TR = mdx::submdspan( Amd, tuple{0,Nhalf},tuple{Nhalf,N} );
  auto A_BL = mdx::submdspan( Amd, tuple{Nhalf,N},tuple{0,Nhalf} );
  auto A_BR = mdx::submdspan( Amd, tuple{Nhalf,N},tuple{Nhalf,N} );

  return 0;
}
