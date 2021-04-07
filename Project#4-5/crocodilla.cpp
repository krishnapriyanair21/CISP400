/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/

#include "crocodilla.h"
Crocodilla::Crocodilla ( )
:Reptile()
{
  _croc_type = CrocTypeUnknown;
}
Crocodilla::Crocodilla ( const char* name)
:Reptile (name)
{
  _croc_type = CrocTypeUnknown;
}
Crocodilla::Crocodilla ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, EnviroType)
:Reptile(n,gt,fc,lf,Carnivore,RawMeat,water)
{
  _croc_type = CrocTypeUnknown;
}

Crocodilla::Crocodilla ( const Crocodilla& c )

:Reptile(c)
{
  _croc_type = c._croc_type;
}

Crocodilla::~Crocodilla ( ) {}

Crocodilla& Crocodilla::operator= ( const Crocodilla& c )
{
  Reptile::operator= (c);
  _croc_type = c._croc_type;
  return *this;
}

void Crocodilla::updateCrocType (CrocType c)
{
  _croc_type = c;
}
CrocType Crocodilla::returnCrocType ()
{
  return _croc_type;
}

void Crocodilla::feed() const
{
  cout <<"feed crocodilia" <<endl;
}
void Crocodilla::display()const
{
  Reptile::display();
  cout << "Croc-type: " << _croc_type <<endl;
}
void Crocodilla::cageMaintenance()const
{
  cout << "Look up crocodilla cage maintenance" <<endl;
}

