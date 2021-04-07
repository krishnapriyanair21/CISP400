
/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #1
September 18, 2019

*****************************************************/

#include <iostream>

using namespace std;

#include <ctime>
#include <sys/timeb.h>

double TIME ( void );
bool IsPrime( unsigned long long n );
unsigned long long pow2( unsigned n );
unsigned long long Mersenne( unsigned n );
unsigned long long Sqrt ( unsigned long long n );
bool LucasLehmer ( unsigned long long n );


int main ()
{
  double start;
  double end;
  start = TIME();
  for (unsigned long long i = 2; i <= 61; i++)
  {
    if (LucasLehmer(i))
    {
      cout << i << ": " << Mersenne(i)<<" is prime." <<endl;
      end = TIME (); 
      cout <<"Time for LucasLehmar: " <<(end-start)<< " milliseconds" <<endl;
    }
  }
  start = TIME ();
  for (unsigned long long i = 0; i <= 61; i++)
  {
    if (IsPrime(i))
    {
      if (IsPrime(Mersenne(i)))
      {
        cout << i << ": " <<Mersenne(i)<< " is prime."<<endl;
        end = TIME();
        cout << "Time for IsPrime: " << (end-start) <<" milliseconds" <<endl;
      }
    }
  }
  return 0;
}

double TIME ( void )
{
   struct timeb t;
   ftime(&t);
   return ( ( (1000.0 * t.time) + t.millitm ) );
}

bool IsPrime( unsigned long long n )
{
  if (n<=2) return n==2;
  if (n%2==0) return false;
  for (unsigned long long i =2; i <= Sqrt(n); i++)
  {
    if (n%i == 0)return false;
  } 
  return true;
}
unsigned long long pow2( unsigned n )
{
  return static_cast <unsigned long long> (1) <<n;
}
unsigned long long Mersenne( unsigned n )
{
  return pow2(n) - 1;
}
unsigned long long Sqrt ( unsigned long long n )
{
  if (n == 1) return 1; 
  if (n <= 4) return 2;
  if (n <= 9) return 3;
  unsigned i = 3;
  while ((i * i) < n)
  {
    i++;
  } 
  return (i-1);  
}
bool LucasLehmer ( unsigned long long n )
{
  if (n == 2) return true;
  unsigned long long s = 4;
  unsigned long long M = Mersenne(n);
  for (unsigned long long i = 0; i < n-2; i++)
  {
    s = ((s*s) - 2) % M;
  }
  if (s == 0) return true;
  else return false;
}
