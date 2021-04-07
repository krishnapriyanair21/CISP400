
/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #2
October 2, 2019

*****************************************************/


#include "Vector.h"

Vector::Vector()
{
  _x = 0;
  _y = 0;
  _z = 0;
}

Vector::Vector(double X, double Y, double Z)
{
  _x = X;
  _y = Y;
  _z = Z;
}

void Vector::display() const
{
  cout << "<" << _x << ", " << _y << ", " << _z << ">" <<endl;
}

void Vector::add(const Vector& v)
{
  _x += v._x;
  _y += v._y;
  _z += v._z;
}

void Vector::sub(const Vector& v)
{
  _x -= v._x;
  _y -= v._y;
  _z -= v._z;
}

void Vector::mult(const double& d)
{
  _x *= d;
  _y *= d;
  _z *= d;
}

void Vector::div(const double& d)
{
  _x /= d;
  _y /= d;
  _z /= d;
}

void  Vector::normalize()
{
  div(length());
}

double Vector::length()const
{
  return sqrt(_x *_x + _y * _y + _z * _z);
}


