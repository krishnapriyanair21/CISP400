/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #2
October 2, 2019

*****************************************************/

#ifndef VECTOR_H_KN

#define VECTOR_H_KN

#include <iostream>
#include <cmath>  

using namespace std;

class Vector

{

  double _x;
  double _y;
  double _z;
public:
  Vector();
  Vector(double X, double Y, double Z = 0.0);

  void display() const; // <_x, _y, _z>
  void add(const Vector&);
  void sub(const Vector&);
  void mult(const double&);
  void div(const double&);
  void normalize();
  double length()const;

};

#endif 
