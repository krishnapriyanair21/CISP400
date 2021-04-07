/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #3
October 9, 2019

*****************************************************/

#include <iostream>
#include "Vector.h"

using namespace std;
int main()
{
  Vector v1 = {1,2,3};
  Vector v2 = {2,4,6};
  Vector v3 = {3,6};
  Vector v4 = {8,1,5};
  Vector v5;
  Vector v6 = {2,1,3};
  Vector v7 = {-1,2,0};
  double d = 2;
  

  cout << "v1: " << v1 <<endl << "v2: " << v2  <<endl;
  cout << "v3: " << v3 <<endl << "v4: " << v4 <<endl;
  cout <<endl;


  v4 = v1 + v2;
  cout << "v4: (v1+ v2) " << v4 <<endl;
  cout<< "length of v4: " << v4.length() <<endl <<endl;
  v3 = v1 - v2;
  cout << "v3: (v1 - v2) " << v3 <<endl;
  cout <<"length of v3: " << v3.length() <<endl <<endl;
  v4 = d * v4;
  cout << "v4: (d * v4) " << v4 <<endl;
  v3 = v3 / d;
  cout << "v3: (v3 / d) " << v3 <<endl;
  cout<<endl;


  if (v1 != v2) cout <<"v1 != v2" <<endl;
  v5=v1;
  if (v5 == v1) cout <<"v5 == v1" <<endl;
  cout<<endl;


  cout <<"dot product of  v3 and v5: " <<v3.dotProduct(v5) <<endl;
  cout << "cross product of v3 and v5: " << v3.crossProduct(v5) <<endl;
  cout <<endl;


  cout <<"normalizing..." <<endl;
  v1.normalize();
  v2.normalize ();
  v3.normalize();
  v4.normalize();
  v5.normalize();



  cout << endl << "v1: " << v1 << endl;
  cout << "v2: " <<v2 <<endl;
  if (v1.parallel(v2)) cout <<"v1 and v2 are parallel!" <<endl <<endl;

  cout << "v6: " << v6 <<endl << "v7: " << v7 <<endl;

  if (v6.perpendicular(v7))
  {
    cout <<"v6 is perpendicular to v7" <<endl;
  } 
  else 
  { 
    cout<<"oops! not perpendicular" <<endl;
  }
  return 0;
}
