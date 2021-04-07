/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/
#include "giraffe.h"

Giraffe::Giraffe ( )
:Mammal()
{
  _height = 0.0; 
}
Giraffe::Giraffe ( const char* name)
:Mammal(name)
{
  _height = 0.0;
}
Giraffe::Giraffe ( const char* n, const GenderType& gt,
         double fc, double lf, double h)
:Mammal(n,gt,fc,lf,Herbivore,Leaves, 97.5, 98, 97)
{
  _height = 0.0;
}
Giraffe::Giraffe ( const Giraffe& g)
:Mammal(g)
{
  _height = g._height;
}

Giraffe::~Giraffe ( ){}

Giraffe& Giraffe::operator= ( const Giraffe& g)
{
  Mammal::operator=(g);
  _height = g._height;
  return *this;
}

void Giraffe::updateHeight(double h)
{
  _height = h;
}
double Giraffe::returnHeight()
{
  return _height;
}
bool Giraffe::heightInRange()
{
  return ((_height >= MIN_HEIGHT) && (_height <= MAX_HEIGHT)) ;
}

void Giraffe::feed() const
{
  cout <<"feed giraffe" <<endl;
}
void Giraffe::display()const
{
  Mammal::display();
  cout << "Height in feet: " << _height <<endl;
}
void Giraffe::cageMaintenance()const
{
  cout <<"Look up Giraffe Cage Maintenance" <<endl;
}

