class MyClass
{
public:
  
}

class Complex
{
  double r, i;

public:
  //                          complex variable
  //                            |
  //                            | variable
  //                            |  |
  Complex(double r, double i) : r(_r), i(i)
  //                              |
  //                            coping
  {
    this->r = r;
    this->i = i;
  }
};
