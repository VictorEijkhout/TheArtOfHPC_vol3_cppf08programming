#include <tuple>
class coordinate : public std::pair<float,float> {
public:
  coordinate( float x,float y ){};
  coordinate operator*( float rate ) const {
    return coordinate(0.f,0.f);
  };
};

