/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/

#include "greenSeaTurtle.h"

GreenSeaTurtle::GreenSeaTurtle ( )
:Reptile()
{
  _length = 0.0;
}
GreenSeaTurtle::GreenSeaTurtle ( const char* name)
:Reptile(name)
{
  _length = 0.0;
}
GreenSeaTurtle::GreenSeaTurtle ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt, const FeedType& ft,
         EnviroType)
:Reptile(n,gt,fc,lf,Omnivore, RawFish, water)
{
  _length = 0.0;
}
GreenSeaTurtle::GreenSeaTurtle ( const GreenSeaTurtle& g )
:Reptile(g)
{
  _length = g._length;
}

GreenSeaTurtle::~GreenSeaTurtle ( ){}
GreenSeaTurtle& GreenSeaTurtle::operator= ( const GreenSeaTurtle& g)
{
  Reptile::operator= (g);
  _length = g._length;
  return *this;
}

void GreenSeaTurtle::updateLength (double l)
{
  _length = l;
}
double GreenSeaTurtle::returnLength ()
{
  return _length;
}
bool GreenSeaTurtle::lengthInRange ()
{
  return ((_length > MIN_LENGTH) && (_length < MAX_LENGTH));
}

void GreenSeaTurtle::feed() const
{
  cout <<"feed green sea turtle" <<endl;
}
void GreenSeaTurtle::display()const
{
  Reptile::display();
  cout << "Length-in-Feet: " << _length <<endl;
}
void GreenSeaTurtle::cageMaintenance()const
{
  cout <<"Look up Green Sea Turtle cage Maintenance" <<endl;
}

