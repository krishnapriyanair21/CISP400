/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #5
November 6, 2019

*****************************************************/

#include <iostream>
#include "animal.h"
#include "bird.h"
#include "mammal.h"
#include "reptile.h"
#include "eagle.h"
#include "crocodilla.h"
#include "giraffe.h"
#include "greenSeaTurtle.h"
#include "raccoon.h"


using namespace std;

const int MAX_ANIMALS = 10;

class Zoo
{
  Animal* _zoo[MAX_ANIMALS];
  unsigned _num_animals;
  void _add_animal();
  void add_eagle();
  void add_giraffe();
  void add_raccoon();
  void add_turtle();
  void add_croc();
  void _cage_maintenance();
  void _feed_all();
  void _display_all();

public:
  Zoo();
  ~Zoo();

};

