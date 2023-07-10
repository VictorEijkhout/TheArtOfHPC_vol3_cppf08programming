/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** adjacent2.cxx : adjacency matrix implementation, sparse
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

class AdjacencyMatrix {
private:
  vector< vector<int> > pages;
public:
  AdjacencyMatrix(int size) {
    pages = vector<vector<int>>(size);
  };
  //! Add a page by setting the corresponding boolean.
  //! This models a link from page i to page j.
  void addpage(int i,int j) {
    // test whether i,j already exists
    pages.at(i).push_back(j);
  };
  //! Count the number of links from a page.
  int number_of_outlinks(int page) {
    return pages.at(page).size();
  };
  //! Given a probability vector, compute a new vector
  vector<float> transition( vector<float> state ) {
    // basic compatibility checking
    int n = state.size();
    if (n!=pages.size()) {
      cout << "State vector has length " << n
	   << "; incompatible with matrix of size " << pages.size() << '\n';
      throw(1); }
    vector<float> newstate(n,0.);
    for (int page=0; page<n; ++page) {
      if (state.at(page)>0) {
	// if we are on page `page'
	float probability_per_link = 1./number_of_outlinks(page);
	float probability_for_page = state.at(page);
	for ( auto link : pages.at(page) ) { // (int link=0; link<n; ++link) {
	  // follow all the links
	  newstate.at(link) += probability_per_link * probability_for_page;
	}
      }
    }
    return newstate;
  };
  void print() {
    for (int irow=0; irow<pages.size(); ++irow) {
      cout << "Page " << irow << " has links: ";
      for (auto col : pages.at(irow))
	cout << col << ", ";
      cout << '\n';
    }
  };
};

int main() {

  int number_of_pages = 25, max_nzeros_per_row = 4;
  AdjacencyMatrix web(number_of_pages);

  // fill in matrix
  float fraction=0., target_fraction = 1.1/number_of_pages;
  for (int itry=0; fraction<target_fraction; ++itry)
    fraction = ( (float)rand() )/RAND_MAX;
  cout << "filling up to fraction " << fraction << '\n';
  int total_nzeros = number_of_pages * max_nzeros_per_row * fraction;
  cout << "creating matrix with " << total_nzeros << " nonzeros" << '\n';
  for (int inz=0; inz<total_nzeros; ++inz) {
    fraction = ( (float)rand() )/RAND_MAX;
    int row = number_of_pages * fraction;
    fraction = ( (float)rand() )/RAND_MAX;
    int col = number_of_pages * fraction;
    try {
      web.addpage(row,col);
    } catch (...) {
      cout << "Could not add page (" << row << "," << col << ")" << '\n';
      throw(1);
    }
  }

  // print matrix
  web.print();

  // start on a random page
  vector<float> probability_vector(number_of_pages,0.), new_probability;
  {
    int random_page = number_of_pages * ( (float)rand() )/RAND_MAX;
    probability_vector.at(random_page) = 1.;
  }

  // now do a number of transition steps
  for (int step=0; step <5; ++step) {
    cout << "Step " << step << '\n';
    int page;
    for (page=0; page<number_of_pages; ++page) {
      if (web.number_of_outlinks(page)>0) {
	new_probability = web.transition(probability_vector);
	float sum_of_probabilities{0};
	int count{0};
	for ( auto p : new_probability ) {
	  sum_of_probabilities += p; ++count ; }
	cout << "On page " << page << ", sum of " << count << " outgoing probabilities="
	     << sum_of_probabilities << '\n';
      }
    }
    cout << '\n';
  }

  return 0;
}
