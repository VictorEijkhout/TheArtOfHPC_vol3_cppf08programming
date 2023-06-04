/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** iter.cxx : tinkering with iterators
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <cassert>

int main() {


  if (false) {
    cout << "BeginEnd\n";
    vector<float> empty;
    auto b = empty.begin();
    auto e = empty.end();
    if (b==e)
      cout << "Begin equals end\n";
    try {
      float f = *b;
      cout << "begin is: " << f << '\n';
    } catch (...) {
      cout << "Could not take begin\n";
    }
    cout << "beginend\n";
  }

  {
    cout << "Copy\n";
    //codesnippet itercopy
    vector<int> counts{1,2,3,4};
    vector<int> copied(5);
    copy( counts.begin(),counts.end(),
          copied.begin()+1 );
    cout << copied[0] 
         << ", " << copied[1]
         << ".." << copied[4] << '\n';
    //codesnippet end
    cout << "copy\n";
  }

  {
    cout << "PlusMinus\n";
    //codesnippet iterplusminus
    vector<int> counts{1,2,3,4};
    auto second = counts.begin(); second++;
    cout << "Second element: " << *second << '\n';
    auto last = counts.end(); last--;
    cout << "Last element: " << *last << '\n';
    //codesnippet end
    cout << "plusminus\n";
  }

  {
    cout << "Erase2\n";
    //codesnippet vectorerase
    vector<int> counts{1,2,3,4,5,6};
    vector<int>::iterator second = counts.begin()+1;
    auto fourth = second+2;
    counts.erase(second,fourth);
    cout << counts[0]
         << "," << counts[1] << '\n';
    //codesnippet end
    cout << "erase2\n";
  }
  
  {
    cout << "Insert2\n";
    //codesnippet vectorinsert
    vector<int> counts{1,2,3,4,5,6},
      zeros{0,0};
    auto after_one = zeros.begin()+1;
    zeros.insert
      ( after_one,
        counts.begin()+1,
        counts.begin()+3 );
    cout << zeros[0] << ","
         << zeros[1] << ","
         << zeros[2] << ","
         << zeros[3]
         << '\n';
    //codesnippet end
    cout << "insert2\n";
    //vector<int>::insert( after_one,counts.begin()+1,counts.begin()+3 );
  }
  
  {
    cout << "Subvectorcopy" << '\n';
    //codesnippet subvectorcopy
    vector<int> vec{11,22,33,44,55,66};
    auto second = vec.begin(); second++;
    auto before = vec.end(); before--;
    vector<int> sub(vec.data()+1,vec.data()+vec.size()-1);
    cout << "no first and last: ";
    for ( auto i : sub ) cout << i << ", ";
    cout << '\n';
    //codesnippet end
    cout << ".. subvectorcopy" << '\n';

    cout << "Subvectornew" << '\n';
    //codesnippet subvectornew
    vec.at(1) = 222;
    cout << "did we get a change in the sub vector? "
	 << sub.at(0) << '\n';
    //codesnippet end
    cout << ".. subvectornew" << '\n';
  }

  {
    cout << "Subvectorassign" << '\n';
    //codesnippet subvectorcopy
    vector<int> vec{11,22,33,44,55,66};
    auto second = vec.begin(); second++;
    auto before = vec.end(); before--;
    //    vector<int> sub(second,before);
    vector<int> sub; sub.assign(second,before);
    cout << "vector at " << (long)vec.data() << '\n';
    cout << "sub at " << (long)sub.data() << '\n';

    cout << "no first and last: ";
    for ( auto i : sub ) cout << i << ", ";
    cout << '\n';
    vec.at(1) = 222;
    cout << "did we get a change in the sub vector? " << sub.at(0) << '\n';
    //codesnippet end
    cout << ".. subvector" << '\n';
  }

  {
    cout << "Subpointer" << '\n';
    //codesnippet subpointer
    auto vec = shared_ptr<vector<int>>(new vector<int>{11,22,33,44,55,66});
    auto second = vec->begin(); second++;
    auto before = vec->end(); before--;
    auto sub = shared_ptr<vector<int>>(new vector<int>(second,before));
    cout << "vector at " << (long)vec->data() << '\n';
    cout << "sub at " << (long)sub->data() << '\n';
    cout << "no first and last: ";
    for ( auto i : *(sub.get()) ) cout << i << ", ";
    cout << '\n';    
    vec->at(1) = 222;
    cout << "did we get a change in the sub vector? " << sub->at(0) << '\n';
    //codesnippet end
    cout << ".. subpointer" << '\n';
  }

  {
    //codesnippet iterderef
    vector<int> vec{11,22,33,44,55,66};
    auto second = vec.begin(); second++;
    cout << "Dereference second: "
         << *second << '\n';
    // DOES NOT COMPILE
    // the iterator is not a type-star:
    // int *subarray = second;
    //codesnippet end  
  }

  return 0;
}
