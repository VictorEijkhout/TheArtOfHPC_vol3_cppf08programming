  cout << "Simple\n";
  {
    //codesnippet pointfunc
    Point p1(1.,2.);
    cout << "p1 has length "
         << p1.length() << '\n';
    //codesnippet end
  }
  cout << "simple\n";
  
  cout << "Cout\n";
  {
    //codesnippet pointfuncout2
    Point p1(1.,2.);
    cout << "p1 " << p1
         << " has length "
         << p1.length() << '\n';
    //codesnippet end
  }
  cout << "cout\n";

  return 0;
}
