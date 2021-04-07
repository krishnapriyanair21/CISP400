/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/

#include "mammal.h"

Mammal::Mammal ( )
:Animal()
{
  _body_temp = 0;
  _high_temp = 0;
  _low_temp = 0;
}
Mammal::Mammal ( const char* name )
:Animal(name)
{
  _body_temp = 0;
  _high_temp = 0;
  _low_temp = 0;

}

Mammal::Mammal ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, double bt, double ht, double lt)
:Animal(n,gt, fc, lf, dt, ft)
{
  _body_temp = bt;
  _high_temp = ht;
  _low_temp = lt;
}
Mammal::Mammal ( const Mammal& m )
:Animal(m)
{
  _body_temp = m._body_temp;
  _high_temp = m._high_temp;
  _low_temp = m._low_temp;
}

Mammal::~Mammal ( ){ }

Mammal& Mammal::operator= ( const Mammal& m)
{
  Animal::operator=(m);
  _body_temp = m._body_temp;
  _high_temp = m._high_temp;
  _low_temp = m._low_temp;
  return *this;
}

void Mammal::bodyTemperature (double bt)
{
  _body_temp = bt;
}
double Mammal::bodyTemperature ()
{
  return _body_temp;
}

bool Mammal::inRange()
{
  return ((_low_temp < _body_temp) && (_body_temp < _high_temp));
}
