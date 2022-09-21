#include <iostream>
using namespace std;

#include "complex.h"

Complex operator + (double a, Complex& b) {
  Complex d;
  d.r = a + b.r;
  d.i = b.i;
  return d;
}

Complex::Complex () {
}

Complex::Complex(double r, double i) {
  cout << "Object was created " << r << " + i*" << i << endl;
  mas = new int;
}

Complex::~Complex() {
  cout << "Object was destroyed" << endl;
  delete mas;
}

Complex Complex::operator + (Complex& b) {
  Complex c;
  c.r = r + b.r; // this->r
  c.i = i + b.i;
  return c;
}

Complex& Complex::operator = (const Complex& c) {
  r = c.r;
  i = c.i;
  return *this;
}

Complex& Complex::operator + (double b) {
  Complex d;
  d.r = r + b;
  d.i = i;
  return d;
}

void Complex::Add(Complex& c) {
  r += c.r;
  i += c.i;
}

Complex Complex::Inversed() {
  Complex x(i, r);
  // Complex(*this) - явный вызов конструктора копирования
  return x; // констркутор копирования вызывается при возвращении
}
