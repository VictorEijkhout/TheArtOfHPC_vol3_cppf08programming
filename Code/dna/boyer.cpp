/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** boyer.cxx : boyer-moore matching of reads
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

#include <optional>
using std::optional;

#include <tuple>
using std::make_tuple;
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
 * Some basic functions for read matching
 */
tuple<int,int,int> string_find_suffix(string basestring,int baseloc,string read) {
  int readlength = read.size();
  int suffixlength=0, genepointer = baseloc+readlength-1,readpointer = readlength-1;
  for ( ;
	suffixlength<readlength && basestring[genepointer]==read[readpointer];
	genepointer--,readpointer--,++suffixlength)
    ;
  //cout << "at " << genepointer << " match on " << basestring[genepointer] << '\n' ;
  if (suffixlength<readlength)
    cout << "at " << genepointer << " mismatch on " << basestring[genepointer] << '\n' ;
  return {suffixlength,genepointer,readpointer};
}

int find_mismatched_char_in_read(char badchar,string read,int readpointer) {
  int badcharskip = 0;
  for ( ; readpointer-badcharskip>=0 && read[readpointer-badcharskip]!=badchar;
	++badcharskip )
    ;
  cout << "looking for " << badchar << " we skip back by " << badcharskip << '\n' ;
  return badcharskip;
}

/*
 * Genomes are handled with proper OOP techniques
 */
class genome {
private:
  string _basestring;
public:
  genome(string input,bool literal=false) {
    if (literal)
      _basestring = input;
    else {
      ifstream input_file;
      input_file.open(input);
      string oneline, genome;
      while (input_file) {
	getline(input_file,oneline);
	if (oneline[0]=='>') continue;
	if (oneline.size()==0) continue;
	genome += oneline;
      }
      input_file.close();
      _basestring = genome;
    }
  };
  const auto &basestring() const { return _basestring; };
  auto size() const { return _basestring.size(); };
  auto FakeReads(int nreads,int length) {
    vector<string> reads;
    for (int iread=0; iread<nreads; ++iread) {
      int loc = (_basestring.size()-length) * ( rand()/(float)RAND_MAX );
      //cout << "read @ " << loc << '\n';
      reads.push_back( _basestring.substr(loc,length) );
    }
    return reads;
  }
  tuple<int,int,int> find_suffix(int baseloc,string read) {
    return string_find_suffix(_basestring,baseloc,read); }
  optional<int> matchread( string read,int strategy=3 ) {
    auto readlength = read.size();
    int baseloc=0;
    for ( ; baseloc<=_basestring.size()-readlength; ) {
      // try aligning at baseloc
      /*
	1. Find the longest suffix. We maintain these invariants:
	suffixlength : the number of matched bases from the tail
	genepointer  : the location in the genome we are matching
	readpointer  : the location in the read we are matching
      */
      auto [suffixlength,genepointer,readpointer] = find_suffix(baseloc,read);
      // Invariant violated;
      // possibility 1: we have a full match
      if (suffixlength==readlength)
	return baseloc;
      if (strategy==1) { ++baseloc ; continue ; }
      // Possibility 2: mismatched character.
      auto badcharskip = find_mismatched_char_in_read(_basestring[genepointer],read,readpointer);
      baseloc += badcharskip;
    }
    return {};
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

#define ASSERT(a,b) \
  if (a) { cout << "SUCCESS: "; }   \
  else   { cout << "FAILED to: "; } \
  cout << b << '\n';

int main() {

  complement.insert(make_pair('A','T'));
  complement.insert(make_pair('T','A'));
  complement.insert(make_pair('C','G'));
  complement['G'] = 'C';
  complement['N'] = 'N';

  // first some unit tests
  {
    genome test1("ATTC",true);
    {
      string read{"AT"};
      cout << "Trying to match " << read << " to " << test1.basestring() << '\n';
      auto matchloc = test1.matchread(read);
      ASSERT(matchloc,"AT matched");
      ASSERT(*matchloc==0,"AT matched at zero");
    }
    {
      string read{"ATTC"};
      cout << "Trying to match " << read << " to " << test1.basestring() << '\n';
      auto matchloc = test1.matchread(read);
      ASSERT(matchloc,"ATTC matched");
      ASSERT(matchloc.value()==0,"ATTC matched at zero");
    }

    genome test2("ATTC",true);
    {
      string read{"TT"};
      cout << "Trying to match " << read << " to " << test2.basestring() << '\n';
      auto matchloc = test2.matchread(read,1);
      ASSERT(matchloc.value()==1,"TTC matched at one");
    }
    {
      string read{"TTC"};
      cout << "Trying to match " << read << " to " << test2.basestring() << '\n';
      auto matchloc = test2.matchread(read,1);
      ASSERT(matchloc.value()==1,"TTC matched at one");
    }
    {
      string read{"TTC"};
      cout << "Trying to match " << read << " to " << test2.basestring() << '\n';
      auto matchloc = test2.matchread(read,2);
      ASSERT(matchloc.value()==1,"TTC matched at one");
    }

    genome test3("GATCTACTTCA",true);
    { // find perfect match with badcharskip
      string read{"TTC"};
      cout << "Trying to match " << read << " to " << test3.basestring() << '\n';
      auto matchloc = test3.matchread(read,2);
      ASSERT(matchloc,"TTC matched");
      ASSERT(matchloc.value()==7,"TTC matched at 7");
    }
    { // find incomplete match
      auto [suffixlength,genepointer,readpointer] =
    	test3.find_suffix(1,"TACT");
      ASSERT(suffixlength==2,"Suffix length found is 2");
      ASSERT(readpointer==1,"Second char mismatched, so read pointer==1");
      ASSERT(genepointer==2,"Mismatch on third char in gene");
    }
  }
  return 0;
#if 0
  genome phix("phix.fa");

  cout << "Genome has length " << phix.size() << '\n';

  { // using fake reads
    auto reads = phix.FakeReads(25,5); reads[12] = "XYY";
    int nmatch{0};
    for ( auto r : reads ) {
      auto matchloc = phix.matchread(r);
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
      auto matchloc = phix.matchread(sub);
      //cout << "match " << sub << " : " << match << '\n';
      sub = ReadReverse(ReadComplement(r).substr(0,30));
      auto [matchc,locc] = phix.matchread(sub);
      //cout << "cmatch " << sub << " : " << match << '\n';
      nmatch += match || matchc;
    }
    cout << "Number of matches: " << nmatch << " out of " << reads.size() << '\n';
  }
#endif

  return 0;
}
