/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #5
November 6, 2019

*****************************************************/

#include "zoo.h"
#include <cstring>


char main_menu();
char add_menu();

Zoo::Zoo()
{
  for (unsigned i = 0; i < MAX_ANIMALS ; i++ )
  {
    _zoo[i] = NULL;
  }
  _num_animals = 0;
  char choice = main_menu();
  while (true)
  {
    switch (choice)
    {
      case '1': {
                cout << "Place new animal in the Zoo" <<endl <<endl;
                _add_animal();
                break;
                }
      case '2': {
                cout << "Cage Maintenance" <<endl <<endl;
                _cage_maintenance();
                break;
                }
      case '3': {
                cout <<"Feed the animals " <<endl<<endl;
                _feed_all();
                break;
                }
      case '4': {
                cout <<"Display all animals" <<endl<<endl;
                _display_all();
                break;
                }
      default: {
               cout <<endl<<"Exit" <<endl;
               return;
               }
    }
  choice = main_menu();
  }

}

Zoo::~Zoo()
{
  for (unsigned i=0; i < _num_animals; i++)
  {
    delete _zoo[i];
  }
  _num_animals = 0;
}


char main_menu ()
{
  cout <<"1. Place a new animal into the Zoo if there is room." <<endl;
  cout <<"2. Do cage maintenance for the Zoo." <<endl;
  cout <<"3. Feed the animals." <<endl;
  cout <<"4. Display all of the animals in the Zoo" <<endl;
  cout <<"5. Exit the simulation." <<endl;
  char choice;
  cin >> choice;
  return choice;
}

char add_menu()
{
  cout << "1. eagle" <<endl;
  cout << "2. giraffe" <<endl;
  cout << "3. raccoon" <<endl;
  cout << "4. green sea turtle" <<endl;
  cout << "5. crocodilia" <<endl;
  char choice;
  cin >> choice;
  return choice;
}

void Zoo::_add_animal()
{
  char choice = add_menu();
  if (_num_animals >= MAX_ANIMALS)
  {
   cout <<"Zoo is full" <<endl;
   return; 
  }
  switch (choice) 
  {
    case '1': add_eagle(); break;
    case '2': add_giraffe(); break;
    case '3': add_raccoon(); break;
    case '4': add_turtle(); break;
    case '5': add_croc(); break;
    default: cout <<"animal not specified" <<endl; return; 
  }
  _num_animals++;
}

void Zoo::add_eagle()
{
  char name[25] = {0};
  char en[] = "Eagle___";
  strcpy(name,en);
  static unsigned char name_num = 0;
  name[7] = name_num %10+ '0';
  name[6] = name_num /10 %10 +'0';
  name[5] = name_num /100 +'0';
  ++name_num;
  _zoo[_num_animals] = new Eagle(name);
}
void Zoo::add_giraffe()
{
  char name[25] = {0};
  char en[] = "Giraffe___";
  strcpy(name,en);
  static unsigned char name_num = 0;
  name[9] = name_num %10+ '0';
  name[8] = name_num /10 %10 +'0';
  name[7] = name_num /100 +'0';
  ++name_num;
  _zoo[_num_animals] = new Giraffe(name);

}
void Zoo::add_raccoon()
{
  char name[25] = {0};
  char en[] = "Raccoon___";
  strcpy(name,en);
  static unsigned char name_num = 0;
  name[9] = name_num %10+ '0';
  name[8] = name_num /10 %10 +'0';
  name[7] = name_num /100 +'0';
  ++name_num;
  _zoo[_num_animals] = new Raccoon(name);

}
void Zoo::add_turtle()
{
  char name[25] = {0};
  char en[] = "GreenSeaTurtle___";
  strcpy(name,en);
  static unsigned char name_num = 0;
  name[16] = name_num %10+ '0';
  name[15] = name_num /10 %10 +'0';
  name[14] = name_num /100 +'0';
  ++name_num;
  _zoo[_num_animals] = new GreenSeaTurtle(name);

}
void Zoo::add_croc()
{
  char name[25] = {0};
  char en[] = "Crocodilia___";
  strcpy(name,en);
  static unsigned char name_num = 0;
  name[12] = name_num %10+ '0';
  name[11] = name_num /10 %10 +'0';
  name[104] = name_num /100 +'0';
  ++name_num;
  _zoo[_num_animals] = new Crocodilla(name);
}

void Zoo::_cage_maintenance()
{
  for (unsigned i = 0 ; i< _num_animals; i++)
  {
    _zoo[i] -> cageMaintenance();
    cout<<endl;
  }
}
void Zoo::_feed_all()
{
  for (unsigned i = 0 ; i< _num_animals; i++)
  {
    _zoo[i] -> feed();
    cout<<endl;
  }

}
void Zoo::_display_all()
{
 for (unsigned i = 0 ; i< _num_animals; i++)
  {
    _zoo[i] -> display();
    cout<<endl;
  }

}
