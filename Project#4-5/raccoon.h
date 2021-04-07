/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/

#ifndef RACCOON_H_KN_
#define RACCOON_H_KN_

#include <iostream>
#include "mammal.h"
using namespace std;

class Raccoon : public Mammal
{
  double _birth_weight;

public:
  Raccoon ( );
  Raccoon ( const char* );
  Raccoon ( const char* n, const GenderType& gt,
         double fc, double lf, double h);
  void Name(const char* c ){ cout <<"Raccoon: "<< c << endl; }
  Raccoon ( const Raccoon& );

  ~Raccoon ( );

  Raccoon& operator= ( const Raccoon& );

  void updateWeight (double);
  double returnWeight();

  void feed() const;
  void display()const;
  void cageMaintenance()const;

};

#endif
