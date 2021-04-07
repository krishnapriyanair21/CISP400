/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/

#ifndef GREENSEATURTLE_H_KN_
#define GREENSEATURTLE_H_KN_

#include <iostream>
#include "reptile.h"
using namespace std;

class GreenSeaTurtle : public Reptile
{
  double _length;
  double MAX_LENGTH = 5;
  double MIN_LENGTH = 4;
public:
  GreenSeaTurtle ( );
  GreenSeaTurtle ( const char* );
  GreenSeaTurtle ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt, const FeedType& ft,
         EnviroType);
  void Name(const char* c ){ cout <<"Green Sea Turtle: "<< c << endl; }
  GreenSeaTurtle ( const GreenSeaTurtle& );

  ~GreenSeaTurtle ( );

  GreenSeaTurtle& operator= ( const GreenSeaTurtle& );

  void updateLength (double);
  double returnLength ();
  bool lengthInRange ();

  void feed() const;
  void display()const;
  void cageMaintenance()const;

};


#endif

