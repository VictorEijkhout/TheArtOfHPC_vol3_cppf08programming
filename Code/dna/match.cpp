/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** match.cxx : exact matching of reads
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <algorithm>
using std::reverse_copy;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;
using std::make_pair;

#include <random>
using std::rand;

#include <tuple>
using std::tuple;

/*
 * We declare a global variable for base complements
 */
map<char,char> complement;

auto BaseComplement(char base) {
  if (base=='U') {
    throw(std::string("We don't do RNA"));
  } else if (complement.find(base)==complement.end()) {
    throw(string("Not a valid base: ")+base);
  } else
    return complement[base];
}

auto ReadComplement( string read ) {
  string complmnt(read);
  for ( auto &c : complmnt )
    c = BaseComplement(c);
  return complmnt;
}

auto ReadReverse( string read ) {
  string revrse(read);
  reverse_copy( read.begin(),read.end(),revrse.begin() );
  return revrse;
}

/*
 * Genomes are handled with proper OOP techniques
 */
class genome {
private:
  string basestring;
public:
  genome(string filename) {
    ifstream input_file;
    input_file.open(filename);
    string oneline, genome;
    while (input_file) {
      getline(input_file,oneline);
      if (oneline[0]=='>') continue;
      if (oneline.size()==0) continue;
      genome += oneline;
    }
    basestring = genome;
  };
  auto size() const { return basestring.size(); };
  auto FakeReads(int nreads,int length) {
    vector<string> reads;
    for (int iread=0; iread<nreads; ++iread) {
      int loc = (basestring.size()-length) * ( rand()/(float)RAND_MAX );
      //cout << "read @ " << loc << '\n';
      reads.push_back( basestring.substr(loc,length) );
    }
    return reads;
  }
  auto matchread( string read ) {
    auto readlength = read.size();
    for (int baseloc=0; baseloc<basestring.size()-readlength; ++baseloc) {
      bool match{true};
      for (int readloc=0; readloc<read.size(); ++readloc) {
	if (basestring[baseloc+readloc]!=read[readloc]) {
	  match = false; break;
	}
      }
      if (match)
	//return {match,baseloc};
	return tuple<bool,int>{match,baseloc};
    }
    //return {false,-1};
    return tuple<bool,int>{false,-1};
  };
};

auto ReadFastQ( string filename ) {
  ifstream input_file;
  input_file.open(filename);
  vector<string> genome, quality; int basecount{0};
  while (input_file) {
    string baseline,qualline,oneline;
    // header line
    getline(input_file,oneline);

    // bases line
    getline(input_file,baseline);
    genome.push_back(baseline);

    // another dummy line
    getline(input_file,oneline);

    // quality line
    getline(input_file,qualline);
    if (baseline.size()!=qualline.size()) {
      cout << "Base/quality length mismatch at base " << basecount << '\n';
      break;
    }
    quality.push_back(qualline);
    basecount += 1;
  }
  return tuple<vector<string>,vector<string>>{genome,quality};
}

int main() {

  complement.insert(make_pair('A','T'));
  complement.insert(make_pair('T','A'));
  complement.insert(make_pair('C','G'));
  complement['G'] = 'C';
  complement['N'] = 'N';

  genome phix("phix.fa");
  cout << "Genome has length " << phix.size() << '\n';

  { // using fake reads
    auto reads = phix.FakeReads(25,5); reads[12] = "XYY";
    int nmatch{0};
    for ( auto r : reads ) {
      auto [match,loc] = phix.matchread(r);
      // if (match) 
      // 	cout << "Match: " << r << " @ " << loc << '\n';
      // else
      // 	cout << "No match on " << r << '\n';
      nmatch += match;
    }
    cout << "Number of matches: " << nmatch << " out of " << reads.size() << '\n';
  }

  { // using actual reads
    auto [reads,quals] = ReadFastQ("ERR266411_1.first1000.fastq");
    int nmatch{0};
    for ( auto r : reads ) {
      string sub;
      sub = r.substr(0,30);
      auto [match,loc] = phix.matchread(sub);
      //cout << "match " << sub << " : " << match << '\n';
      sub = ReadReverse(ReadComplement(r).substr(0,30));
      auto [matchc,locc] = phix.matchread(sub);
      //cout << "cmatch " << sub << " : " << match << '\n';
      nmatch += match || matchc;
    }
    cout << "Number of matches: " << nmatch << " out of " << reads.size() << '\n';
  }

  return 0;
}
