
/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #2
October 2, 2019

*****************************************************/


#include "Vector.h"


int main()
{
  Vector v1 = {1,3,5};
  v1.display();
  cout <<endl;

  Vector v2 = {2,4,6};
  v2.display();
  cout <<endl;

  v1.add(v2);
  cout <<"Add v1 + v2 ";
  v1.display();
  cout <<endl<<endl;

  v1.sub(v2);
  cout <<"sub v1 -v2 ";
  v1.display();
  cout <<endl<<endl;

  v2.mult(2);
  cout << "Mult v2*2 ";
  v2.display();
  cout<<endl<<endl;

  v2.div(2);
  cout <<"Div v2/2 ";
  v2.display();
  cout<<endl<<endl;

  cout <<"V1 length = " <<v1.length()<<endl;
  cout <<"v2 length = "<<v2.length() <<endl;
  cout<<endl;

  v1.normalize();
  v2.normalize();
  cout <<"Normalized" <<endl;
  cout <<"v1 = ";
  v1.display();
  cout <<"v2 = "; 
  v2.display();
  cout <<endl;

  cout <<"V1 length = " <<v1.length()<<endl;
  cout <<"v2 length = "<<v2.length() <<endl;
  cout<<endl;

return 0;
}

