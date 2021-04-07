/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/
#ifndef REPTILE_H_KN
#define REPTILE_H_KN

#include <iostream>
#include "animal.h"
using namespace std;

enum EnviroType {water, land};

class Reptile : public Animal
{
  EnviroType _enviro;
public:
  Reptile ( );
  Reptile ( const char* );
  Reptile ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, EnviroType);
  Reptile ( const Reptile& );

  ~Reptile ( );

  Reptile& operator= ( const Reptile& );

  void Enviroment(EnviroType);
  EnviroType Environment ();
};
#endif
