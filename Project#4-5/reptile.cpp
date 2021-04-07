/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/
#include "reptile.h"

Reptile::Reptile ( )
:Animal()
{
  _enviro = water;
}
Reptile::Reptile ( const char* name )
:Animal(name)
{
  _enviro = water;
}
Reptile::Reptile ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, EnviroType et)
:Animal(n,gt, fc, lf, dt, ft)
{
  _enviro = water;
}
Reptile::Reptile ( const Reptile& r )
:Animal(r)
{
  _enviro = r._enviro;
}
Reptile::~Reptile ( ){}

Reptile& Reptile::operator= ( const Reptile& r )
{
  Animal::operator=(r);
  _enviro = r._enviro;
  return *this;
}

void Reptile::Enviroment(EnviroType et)
{
  _enviro = et;
}
EnviroType Reptile::Environment ()
{
  return _enviro;
}

