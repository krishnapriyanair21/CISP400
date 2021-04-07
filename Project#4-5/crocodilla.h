/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #4
October 30, 2019

*****************************************************/

#ifndef CROCODILLA_H_KN_
#define CROCODILLA_H_KN_


#include <iostream>
#include "reptile.h"
using namespace std;

enum CrocType {CrocTypeUnknown, Crocodile, Alligator, Caiman, Gharial };

class Crocodilla : public Reptile
{
  CrocType _croc_type;
public:
  Crocodilla ( );
  Crocodilla ( const char* );
  Crocodilla ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, EnviroType);
  void Name(const char* c ){ cout <<"Crocodilla: "<< c << endl; }
  Crocodilla ( const Crocodilla& );

  ~Crocodilla ( );

  Crocodilla& operator= ( const Crocodilla& );

  void updateCrocType (CrocType);
  CrocType returnCrocType ();

  void feed() const;
  void display()const;
  void cageMaintenance()const;
};

#endif
