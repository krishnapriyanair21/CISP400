/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/
#ifndef GIRAFFE_H_KN_
#define GIRAFFE_H_KN_

#include <iostream> 
#include "mammal.h"
using namespace std;

class Giraffe : public Mammal
{
  double _height;
  const double MAX_HEIGHT = 20.0;
  const double MIN_HEIGHT = 15.0;
public:
  Giraffe ( );
  Giraffe ( const char* );
  Giraffe ( const char* n, const GenderType& gt,
         double fc, double lf, double h);
  void Name(const char* c ){ cout <<"Giraffe: "<< c << endl; }
  Giraffe ( const Giraffe& );

  ~Giraffe ( );

  Giraffe& operator= ( const Giraffe& );

  void updateHeight(double);
  double returnHeight();
  bool heightInRange();

  void feed() const;
  void display()const;
  void cageMaintenance()const;


};

#endif
