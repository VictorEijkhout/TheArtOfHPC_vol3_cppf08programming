/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** virus.cxx : reading a FASTA file
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;
using std::make_pair;

#include <chrono>

map<char,char> complement;

auto BaseComplement(char base) {
  if (base=='U') {
    throw(std::string("We don't do RNA"));
  } else if (complement.find(base)==complement.end()) {
    throw(string("Not a valid base: ")+base);
  } else
    return complement[base];
}

int main() {

  complement.insert(make_pair('A','T'));
  complement.insert(make_pair('T','A'));
  complement.insert(make_pair('C','G'));
  complement['G'] = 'C';

  ifstream input_file;
  input_file.open("lambda_virus.fa");
  string oneline, genome;
  while (input_file) {
    getline(input_file,oneline);
    if (oneline[0]=='>') continue;
    if (oneline.size()==0) continue;
    //cout << "Got line: <<" << oneline << ">>" << '\n';
    genome += oneline;
  }

  //  cout << "Genome:" << genome << '\n';
  cout << "Genome has length " << genome.size() << '\n';

  {
    vector<int> counts(4,0);

    std::chrono::system_clock::time_point point = std::chrono::system_clock::now();
    for (int rep=0; rep<1000; rep++)
    for ( auto c : genome )
      if (c=='A') counts[0]++;
      else if (c=='C') counts[1]++;
      else if (c=='G') counts[2]++;
      else if (c=='T') counts[3]++;
    auto duration = std::chrono::system_clock::now()-point;
    auto millisec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);

    cout
      << "A: " << counts[0] << ", "
      << "C: " << counts[1] << ", "
      << "G: " << counts[2] << ", "
      << "T: " << counts[3] << '\n';
    cout << "(measured in " << millisec_duration.count() << " usec)" << '\n';
  }

  {
    map<char,int> counts{ {'A',0},{'C',0}, {'G',0}, {'T',0} };

    std::chrono::system_clock::time_point point = std::chrono::system_clock::now();
    for (int rep=0; rep<1000; rep++)
    for ( auto c : genome )
      counts[c] += 1;
    auto duration = std::chrono::system_clock::now()-point;
    auto millisec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);

    cout
      << "A: " << counts['A'] << ", "
      << "C: " << counts['C'] << ", "
      << "G: " << counts['G'] << ", "
      << "T: " << counts['T'] << '\n';
    cout << "(measured in " << millisec_duration.count() << " usec)" << '\n';
  }

  {
    vector<int> counts(4,0);

    std::chrono::system_clock::time_point point = std::chrono::system_clock::now();
    for (int rep=0; rep<1000; rep++)
      for ( auto c : genome ) {
	short int ic = (c&15)>>1;
	counts[ic]++;
      }
    auto duration = std::chrono::system_clock::now()-point;
    auto millisec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);

    cout
      << "A: " << counts[0] << ", "
      << "C: " << counts[1] << ", "
      << "G: " << counts[3] << ", "
      << "T: " << counts[2] << '\n';
    cout << "(measured in " << millisec_duration.count() << " usec)" << '\n';
  }


  return 0;
}
