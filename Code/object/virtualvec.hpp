// -*- c++ -*-

//codesnippet virtfuncvirt
class VirtualVector {
private:
public:
  virtual void setlinear(float) = 0;
  virtual float operator[](int) = 0;
};
//codesnippet end
