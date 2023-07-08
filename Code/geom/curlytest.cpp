/* quick and dirty essence of aggregate initialization */
class Point {
private:
  float x,y;
public:
  Point(float ux,float uy) : x(ux),y(uy) {};
};

class Rectangle {
private:
  Point bl,tr;
public:
  Rectangle(Point bl,Point tr) : bl(bl),tr(tr) {};
};

int main() {
  Point origin{0.,0.};
  Rectangle lielow( origin, {5,2} );

  return 0;
}
