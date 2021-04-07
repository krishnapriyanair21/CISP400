/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/
#ifndef MAMMAL_H_KN
#define MAMMAL_H_KN

#include <iostream>
#include "animal.h"
using namespace std;

class Mammal : public Animal
{
  double _body_temp;
  double _high_temp;
  double _low_temp;
public:
  Mammal ( );
  Mammal ( const char* );
  Mammal ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, double bt, double ht, double lt);
  Mammal ( const Mammal& );

  ~Mammal ( );

  Mammal& operator= ( const Mammal& );

  void bodyTemperature (double);
  double bodyTemperature ();
  bool inRange();

};

#endif
