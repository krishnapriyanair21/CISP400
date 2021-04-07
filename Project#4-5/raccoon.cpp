/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/

#include "raccoon.h"

Raccoon::Raccoon ( )
:Mammal()
{
  _birth_weight = 0.0;
}
Raccoon::Raccoon ( const char* name )
:Mammal(name)
{
  _birth_weight = 0.0;
}
Raccoon::Raccoon ( const char* n, const GenderType& gt,
         double fc, double lf, double h)
:Mammal(n, gt, fc, lf, Omnivore, GrubsNGrass, 96, 97, 95)
{
  _birth_weight = 0.0;
}
Raccoon::Raccoon ( const Raccoon& r )
{
  _birth_weight = r._birth_weight;
}

Raccoon::~Raccoon ( ) {}

Raccoon& Raccoon::operator= ( const Raccoon& r )
{
  Mammal::operator= (r);
  _birth_weight = r._birth_weight;
  return *this;
}

void Raccoon::updateWeight (double w)
{
  _birth_weight = w;
}
double Raccoon::returnWeight()
{
  return _birth_weight;
}


void Raccoon::feed() const
{
  cout<<"feed raccoon"<<endl;
}

void Raccoon::display()const
{
  Mammal::display();
  cout << "Birth weight: " << _birth_weight <<endl;
}
void Raccoon::cageMaintenance()const
{
  cout << "Look up Raccoon Cage Maintenance" <<endl;
}

