/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** quality.cxx : dealing with reader quality
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
  input_file.open("SRR835775_1.first1000.fastq");
  string genome, quality; int basecount{0};
  while (input_file) {
    string baseline,qualline,oneline;
    // header line
    getline(input_file,oneline);

    // bases line
    getline(input_file,baseline);
    genome += baseline;

    // another dummy line
    getline(input_file,oneline);

    // quality line
    getline(input_file,qualline);
    if (baseline.size()!=qualline.size()) {
      cout << "Base/quality length mismatch at base " << basecount << '\n';
      break;
    }
    quality += qualline;
    basecount += 1;
  }
  cout << "read " << basecount << " bases" << '\n';

  //  cout << "Genome:" << genome << '\n';
  cout << "Genome has length " << genome.size() << '\n';

  return 0;
}
