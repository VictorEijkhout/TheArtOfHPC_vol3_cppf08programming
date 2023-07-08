int somefunc( float * ) {
  return 5;
}

int main() {
  float x=1;
  int result = somefunc(&x);
  return 0;
}
