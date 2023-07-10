/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** queue.cxx : queue simulation
 ****
 ****************************************************************/

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
#include <iomanip>
using std::setw;

#include <sstream>
using std::stringstream;

#include <cmath>
//using std::max;

#include <random>
using std::rand;
using std::srand;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <numeric>
using std::accumulate;

class Queue {
private:
  float waiting{0};
  float people_per_minute{1};
public:
  // the add method adds a waiting person
  void add(float n=1) {
    if (n<0) {
      cerr << "Adding negative to queue\n"; throw(1); }
    waiting += n;
  };
  auto size() const { return waiting; };

  // the update method progress by one minute,
  // decreasing the number of waiting people
  void update() {
    waiting = fmax(0,waiting-people_per_minute);
    if (waiting<0) {
      cerr << "Update gives negative waiting\n"; throw(1); }
  };

  float throughput() const {
    if (people_per_minute<=0) {
      cerr << "Queue backing up\n"; throw(1); }
    return people_per_minute; };
  void set_throughput(float ppm) { people_per_minute = ppm; };
  float expected_wait() const { return size()/throughput(); };
};

class Complex {
private:
  vector<Queue> queues;
public:
  Complex(int n) : queues(vector<Queue>(n)) {
    for (auto &q : queues )
      q.set_throughput( 5+15*(float)rand()/(float)RAND_MAX );
  };
  float throughput() const {
    float t{0};
    for ( auto q : queues )
      t += q.throughput();
    return t;
  };
  int size() const { return queues.size(); };
  void add(int q,float n=1) { queues.at(q).add(n); };
  void admit_randomly(int n) { int nq = queues.size();
    auto done{0.f};
    for (auto &q : queues) {
      auto ad = n * (float)rand()/(float)RAND_MAX/nq;
      q.add(ad); done += ad;
    }
  };
  void update() {
    for ( auto &q : queues )
      q.update();
  };
  vector<float> expected_waits() const {
    int nq = queues.size();
    vector<float> waits(nq);
    for (int iq=0; iq<nq; ++iq) {
      waits.at(iq) = queues.at(iq).expected_wait();
    }
    return waits;
  };
  int shortest_wait_queue() const {
    int nq = queues.size();
    float minqueue{0};
    auto minwait = queues.at(0).expected_wait();
    for (int iq=0; iq<nq; ++iq) {
      auto wait = queues.at(iq).expected_wait();
      if (wait<minwait) { minqueue = iq; minwait = wait; }
    }
    return minqueue;
  };
  void header() const {
    stringstream rendering;
    rendering << "     ";
    for ( auto q : queues )
      rendering << setw(4) << static_cast<int>(q.throughput()) << " ";
    cerr << rendering.str() << '\n';
  };
  void display(int step=-1) const {
    stringstream rendering;
    if (step>=0)
      rendering << setw(3) << step << ": ";
    else rendering << "     ";
    for ( auto q : queues ) {
      int iq = q.size();
      if (iq<0) {
	cerr << "Displaying negative: " << q.size() << '\n'; throw(1); }
      rendering << setw(4) << iq /* static_cast<int>(q.size()) */ << " ";
    }
    cerr << rendering.str() << '\n';
  };
};

class Person {
private:
};

int main(int argc,char **argv) {
  
  if (argc<3) {
    cerr << "Usage: " << argv[0] << " nqueues nsteps\n";
    return 1;
  }

  int nqueues = atoi(argv[1]),
    nsteps = atoi(argv[2]);
  
  srand(10);
  {
    cout << "Test 1: see the most popular attactions get the longest queues" << '\n';
    Complex queues(nqueues);
    queues.header();
    auto total_add_per_minute = queues.throughput();
    auto people_per_queue = total_add_per_minute / queues.size();

    // let's put some people in the queue
    for (int q=0; q<queues.size(); ++q) 
      queues.add(q,3*people_per_queue);

    // and now let time progress
    for (int step=0; nsteps>0 && step<nsteps; ++step) {
      for (int q=0; q<queues.size(); ++q) 
	queues.add(q,people_per_queue);
      queues.update();
      queues.display(step);
    }
  }

  srand(10);
  {
    cout << "Test 2: people go the single attraction with the shortest queue" << '\n';
    Complex queues(nqueues);
    queues.header();
    int total_add_per_minute = queues.throughput(),
      avg_people_per_queue = total_add_per_minute / queues.size();

    // let's put some people in the queue
    queues.admit_randomly(10*total_add_per_minute);
      
    // and now let time progress
    for (int step=0; nsteps>0 && step<nsteps; ++step) {
      queues.display(step);
      queues.update();
      int best_queue = queues.shortest_wait_queue();
      int most_add = 3*avg_people_per_queue,
	avg_add = (total_add_per_minute-3*avg_people_per_queue)/queues.size();
      // cout << "adding " << most_add << " at " << best_queue << " and "
      // 	   << avg_add << " elsewhere\n";
      for (int q=0; q<queues.size(); ++q) {
	if (q==best_queue)
	  queues.add(q,most_add);
	else
	  queues.add(q,avg_add);
      }
    }
  }

  srand(10);
  {
    cout << "Test 3: people go the shortest queue by ratio" << '\n';
    Complex queues(nqueues);
    queues.header();
    int total_add_per_minute = queues.throughput();

    // let's put some people in the queue
    queues.admit_randomly(10*total_add_per_minute);
      
    // and now let time progress
    for (int step=0; nsteps>0 && step<nsteps; ++step) {
      queues.display(step);
      queues.update();

      auto val = queues.expected_waits();
      float sump{0};
      for ( auto &v  : val ) {
	v = 1./v; sump += v;
      }
      auto scale = total_add_per_minute / sump;
      for (int q=0; q<queues.size(); ++q) {
	auto add = val.at(q)*scale;
	queues.add(q,add);
      }
    }
  }

  return 0;
}
