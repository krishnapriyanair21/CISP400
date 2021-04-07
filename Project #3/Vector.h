
/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #3
October 9, 2019

*****************************************************/


#ifndef VECTOR_H_DEF_

#define VECTOR_H_DEF_

#include <iostream>

#include <cmath>

using namespace std;

class Vector

{
  double _x;
  double _y;
  double _z;

  //private member functions as needed

public:

  Vector( );
  Vector( double X, double Y, double Z=0 );
  Vector ( const Vector& );
  ~Vector();

  Vector& operator= (const Vector&);
  Vector& operator+= (const Vector&);
  Vector& operator-= (const Vector&);
  Vector& operator*= (double);
  Vector& operator/= (double);


  friend ostream& operator<< (ostream&, const Vector&);  // <_x, _y, _z>
  friend istream& operator>> (istream&, Vector&);

// operator>> must read what operator<< writes

  Vector operator+ (const Vector&) const; //[1]
  Vector operator- (const Vector&) const;
  Vector operator* (double) const;
  friend Vector operator* (double, const Vector&);
  Vector operator/ (double) const;


  bool operator== (const Vector&) const;
  bool operator!= (const Vector&) const;


  bool parallel(const Vector&)const;
  bool perpendicular(const Vector&)const;
  void normalize();
  double length() const;
  double dotProduct ( const Vector& )const;
  Vector crossProduct( const Vector& ) const;
 

  Vector operator- () const;
  Vector operator+ () const;

};

#endif
