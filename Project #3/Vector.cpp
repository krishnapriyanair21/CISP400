/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #3
October 9, 2019

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

Vector::Vector ( const Vector& v )
{
  _x = v._x;
  _y = v._y;
  _z = v._z;
}

Vector::~Vector() {}



Vector& Vector::operator= (const Vector& v)
{
  if (this == &v) return *this;
  _x = v._x;
  _y = v._y;
  _z = v._z;
  return *this;
}

Vector& Vector::operator+= (const Vector& v)
{
  _x += v._x;
  _y += v._y;
  _z += v._z;
  return *this;
}

Vector& Vector::operator-= (const Vector& v)
{
  _x -= v._x;
  _y -= v._y;
  _z -= v._z;
  return *this;
}

Vector& Vector::operator*= (double d)
{
  _x *= d;
  _y *= d;
  _z *= d;
  return *this;
}

Vector& Vector::operator/= (double d)
{
  _x /= d;
  _y /= d;
  _z /= d;
  return *this;
}


ostream& operator<< (ostream& os, const Vector& v)
{
  os << '<' << v._x <<',' << v._y << ',' <<v._z <<'>';
  return os;
}

istream& operator>> (istream& is, Vector& v)
{
  char s;
  double x, y, z;
  is >> s >> x >> s >> y >> s >> z >>s;
  v = Vector (x,y,z);
  return is;
}


Vector Vector::operator+ (const Vector& v) const
{
  return Vector(*this) += v;
}

Vector Vector::operator- (const Vector& v) const 
{
  return Vector(*this) -= v;
}

Vector Vector::operator* (double d) const
{
  return Vector(*this) *= d;
}

Vector operator* (double d, const Vector& v)
{
   return Vector (v) *= d; ///check
}

Vector Vector::operator/ (double d) const
{
  if (d == 0.0)
  {
    cout <<"divide by zero" <<endl;
    exit(1);
  }
  return Vector(*this) /= d;
}

bool Vector::operator== (const Vector& v) const
{
  return (_x == v._x) && (_y == v._y) && (_z == v._z);
}
bool Vector::operator!= (const Vector& v) const 
{
  return ! (*this == v);
}

bool Vector::parallel(const Vector& v)const
{
  return (crossProduct (v) == Vector(0,0,0));
}
bool Vector::perpendicular(const Vector& v)const
{
  return (dotProduct(v) == 0);
}
void Vector::normalize()
{
  *this /= length();
}
double Vector::length() const
{
  return sqrt(_x *_x + _y * _y + _z * _z);
}
double Vector::dotProduct ( const Vector& v)const
{
  return ((_x * v._x) + (_y * v._y) + (_z * v._z));
}
Vector Vector::crossProduct( const Vector& v) const
{
  return Vector(_y * v._z - _z * v._y, - _x * v._z + _z * v._x, _x * v._y - _y * v._x); ///check
}


Vector Vector::operator- () const
{
  return Vector (_x,_y,_z) * -1;
}
Vector Vector::operator+ () const
{
  return *this;
}

