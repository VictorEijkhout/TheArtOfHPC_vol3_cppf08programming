/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** adjacent1.cxx : adjacency matrix implementation, dense
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

class Page {
private:
  vector<int> links;
public:
  Page() {};
  Page(int size) {
    links = vector<int>(size,0);
  };
  auto &at(int i) { return links.at(i); };
  void linkto(int j) { links[j] = 1; };
  const int size() const { int count=0;
    for ( auto l : links ) if (links[l]>0) ++count;
    return count;
  };
  // iterating
  auto begin() { return links.begin(); };
  auto end() { return links.end(); };
};

class State {
private:
  vector<float> probabilities;
public:
  State() {};
  State(int size) {
    probabilities = vector<float>(size,0.);
  };
  auto &at(int i) { return probabilities.at(i); };
  void be_at(int i) { probabilities.at(i) = 1.; };
  const int size() const { int count=0;
    for ( auto p : probabilities ) if (p>0) ++count;
    return count;
  };
  void normalize() { float pval = 1./size();
    for ( auto &p : probabilities )
      if (p>0) p = pval;
  };
  State hit_with( Page page ) {
    State update(*this);
    for ( auto link : page )
      update.be_at(link);
    update.normalize();
    return update;
  };
  // iterating
  auto begin() { return probabilities.begin(); };
  auto end() { return probabilities.end(); };
  void print() {
    float sum_of_probabilities{0};
    int count{0};
    cout << "State:";
    for ( int ip=0; ip<probabilities.size(); ++ip) {
      auto p = probabilities.at(ip);
      if (p>0) cout << " " << ip << ":" << p;
      sum_of_probabilities += p; ++count ;
    }
    cout << '\n';
    if (std::abs(1.-sum_of_probabilities)>1.e-6)
      cout << "Uh oh. sum=" << sum_of_probabilities << '\n';
  }
};

class AdjacencyMatrix {
private:
  vector<Page> pages;
public:
  //! Create a square matrix of a specified size.
  //! We allocate a dense array of bools as a vector of vectors.
  AdjacencyMatrix(int size) {
    pages = vector<Page>(size,Page(size));
  };
  //! Add a page by setting the corresponding boolean.
  //! This models a link from page i to page j.
  void addpage(int i,int j) {
    pages.at(i).linkto(j);
  };
  //! Count the number of links from a page.
  int number_of_outlinks(int page) {
    return pages.at(page).size();
  };
  //! Given a probability vector, compute a new vector
  State transition( State state ) {
    for ( auto page : pages )
      state = state.hit_with(page);
    return state;
  };
  void print() {
    for (int irow=0; irow<pages.size(); ++irow) {
      cout << "Page " << irow << " has links: ";
      for (int icol=0; icol<pages.at(irow).size(); ++icol)
	if (pages.at(irow).at(icol))
	  cout << icol << ", ";
      cout << '\n';
    }
  };
};

int main() {

  int number_of_pages = 12, max_nzeros_per_row = 4;
  AdjacencyMatrix web(number_of_pages);
  State probability_vector(number_of_pages);

  {
    cout << "Bidiagonal adjacency matrix" << '\n';
    // fill in matrix
    for (int page=0; page<number_of_pages; ++page) {
      web.addpage(page,page);
      if (page<number_of_pages-1)
	web.addpage(page,page+1);
    }

    // print matrix
    web.print();

    // start on page one
    probability_vector.at(0) = 1.;
  }

  // now do a number of transition steps
  for (int step=0; step <2; ++step) {
    cout << "Step " << step << '\n';
    int page;
    for (page=0; page<number_of_pages; ++page) {
      if (web.number_of_outlinks(page)>0) {
	State new_probability = web.transition(probability_vector);
	new_probability.print();
      }
    }
    cout << '\n';
  }

  return 0;
}
#if 0
  {
    cout << "Bidiagonal adjacency matrix" << '\n';
  // fill in matrix
    for (int page=0; page<number_of_pages; ++page) {
      int nzeros = max_nzeros_per_row * ( (float)rand() )/RAND_MAX;
      for (int zero=0; zero<nzeros; ++zero) {
	int col = max_nzeros_per_row * ( (float)rand() )/RAND_MAX;
	web.addpage(page,col);
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
  }

    // start on a random page
    vector<float> probability_vector(number_of_pages,0.), new_probability;
    {
      int random_page = number_of_pages * ( (float)rand() )/RAND_MAX;
      probability_vector.at(random_page) = 1.;
    }

#endif
