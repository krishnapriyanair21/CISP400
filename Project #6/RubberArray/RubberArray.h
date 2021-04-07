/*****************************************************

Krishnapriya Nair
CISP 400 - MW 5:30 pm
Project #6 and #7
December 11, 2019

*****************************************************/

#ifndef RUBBERARRAY_H_KN
#define RUBBERARRAY_H_KN

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

template <class T>
class RubberArray
{
    T* _array;
    unsigned _alloc;
    unsigned _items;
    int _Vindex;

public:
    RubberArray ( int Vindex = 0 );
    RubberArray ( const T*, unsigned s, int Vindex = 0 );
    RubberArray ( const RubberArray& );
    ~RubberArray();
    RubberArray<T>& operator= (const RubberArray<T>&);
    template <class OS>
    friend ostream& operator<< ( ostream&, const RubberArray<OS>& );
    template <class OS>
    friend ostream& operator<< ( ostream&, const RubberArray<OS>* );
    T& operator[] ( int Vindex );
    const T& operator[] ( int Vindex ) const;
    RubberArray operator( ) ( int Vfirst, int Vlast )const;
    void operator+= ( const T& );
    void operator+= ( const RubberArray& );
    unsigned Length ( ) const;
    void Insert ( int Vindex, const T& );
    void Insert ( const T& );
    void Delete ( );
    void Delete ( int Vindex );
    void Delete ( int Vfirst, int Vlast );
    void write (ofstream&) const;
    void read (ifstream&);
};

template <class T>
RubberArray<T>::RubberArray ( int Vindex)
{
    _array = NULL;
    _alloc = 0;
    _items = 0;
    _Vindex = Vindex;
}
template <class T>
RubberArray<T>::RubberArray( const T* a, unsigned s, int Vindex)
{
    _array = NULL;
    _alloc = 0;
    _items = 0;
    _Vindex = Vindex;
    for (unsigned i = 0; i < s ; i++)
        operator+= (a[i]);
}
template <class T>
RubberArray<T>::RubberArray ( const RubberArray& ra)
{
    _array = NULL;
    _alloc = 0;
    _items = 0;
    _Vindex = ra._Vindex;
    for (unsigned i = 0; i < ra._items; i++ )
        operator+= (ra._array[i]);
}
template<class T>
RubberArray<T>::~RubberArray()
{
    if (_alloc != 0)
    delete [] _array;
}
template <class T>
RubberArray<T>& RubberArray<T>::operator= (const RubberArray<T>& ra)
{
    if (this == &ra)
        return *this;
    if (_alloc != 0)
        delete [] _array;
    _array = NULL;
    _alloc = 0;
    _items = 0;
    _Vindex = ra._Vindex;
    for (unsigned i = 0; i<ra._items ; i++)
        operator+= (ra._array[i]);
}

template <class OS>
ostream& operator<< ( ostream& os, const RubberArray<OS>& ra)
{
    if (ra._items == 0)
        os <<"<empty>" <<endl;
    else{
        os <<ra._array[0];
        for (unsigned i = 1; i< ra._items; i++)
        {
            os<<"," << ra._array[i];
        }
    }
    return os;
}

template <typename OS>
ostream& operator<< ( ostream& os, const RubberArray<OS>* ra)
{
    if (ra._items == 0)
        os <<"<empty>" <<endl;
    else{
        os <<ra._array[0];
        for (unsigned i = 1; i< ra._items; i++)
        {
            os<<"," << ra._array[i];
        }
    }
    return os;
}

template <class T>
T& RubberArray<T>::operator[] ( int Vi )
{
    int Aindex = Vi - _Vindex;
    if ((0 > Aindex) || (_items <= Aindex))
    {
        throw double(1.0);
    }
    return _array[Aindex];
}
template <class T>
const T& RubberArray<T>::operator[] ( int Vi ) const
{
   int Aindex = Vi - _Vindex;
    if ((0 > Aindex) || (_items <= Aindex))
    {
        throw double (2.0);
    }
    return _array[Aindex];
}

template <class T>
RubberArray<T> RubberArray<T>::operator( ) ( int Vfirst, int Vlast )const
{
    int Afirst = Vfirst - _Vindex;
    int Alast = Vlast- _Vindex;
    if ((Afirst < 0 ) || (Afirst >= Alast) || ( Alast > _items))
    {
        throw double (3.0);
    }
    RubberArray<T> ret(_Vindex);
    for (unsigned i =Afirst; i < Alast; i++)
    {
        ret += _array[i];
    }
    return ret;
}

template <class T>
void RubberArray<T>::operator+= ( const T& t)
{
   if (_items >= _alloc)
   {
       if (_alloc == 0)
       {
           _alloc = 2;
           _array = new T[_alloc];
       }
       else
       {
           _alloc *= 2;
           T* temp = new T[_alloc];
           for (unsigned i = 0; i < _items; i++)
            temp[i] = _array[i];
           delete [] _array;
           _array = temp;
       }
   }
   _array[_items++] = t;
}

template <class T>
void RubberArray<T>::operator+= ( const RubberArray& t)
{
    if (_items >= _alloc)
   {
       if (_alloc == 0)
       {
           _alloc = 2;
           _array = new T[_alloc];
       }
       else
       {
           _alloc *= 2;
           T* temp = new T[_alloc];
           for (unsigned i = 0; i < _items; i++)
            temp[i] = _array[i];
           delete [] _array;
           _array = temp;
       }
   }
   _array[_items++] = t;
}

template <class T>
unsigned RubberArray<T>::Length ( ) const
{
    return _items;
}

template <class T>
void RubberArray<T>::Insert ( int Vi, const T& t)
{
    int Aindex = Vi - _Vindex;
    if ((0 > Aindex) || (_items <= Aindex))
    {
        throw double (4.0);
    }
    RubberArray<T> temp(_Vindex);
    for (unsigned i = 0; i < _items; i++)
    {
        if (i == Aindex)
            temp += t;
        temp += _array[i];
    }
    *this = temp;
}
template <class T>
void RubberArray<T>::Insert ( const T& t)
{
    RubberArray<T> temp(_Vindex);
    temp += t;
    for (unsigned i = 1; i< _items; i++)
    {
        temp += _array [i];
    }
    *this = temp;
}

template <class T>
void RubberArray<T>::Delete ( )
{
    Delete(_Vindex);
}

template <class T>
void RubberArray<T>::Delete ( int Vi)
{
    int Aindex = Vi - _Vindex;
    if ((0 > Aindex) || (_items <= Aindex))
    {
        throw double (5.0);
    }
    RubberArray<T> temp(_Vindex);
    for (unsigned i = 0; i < _items; i++)
    {
        if (i != Aindex)
            temp += _array[i];
    }
    *this = temp;
}


template <class T>
void RubberArray<T>::Delete ( int Vfirst, int Vlast )
{
    int Afirst = Vfirst - _Vindex;
    int Alast = Vlast- _Vindex;
    if ((Afirst < 0 ) || (Afirst >= Alast) || ( Alast > _items))
    {
        throw double (6.0);
    }
    RubberArray<T> temp(_Vindex);
    for (unsigned i = Afirst; i < Alast; i++)
    {
        Delete(Vfirst);
    }
}

template <class T>
void RubberArray<T>::write (ofstream& fout) const
{
    if (fout)
    {
        fout.write(reinterpret_cast<const char*> (&_items), sizeof (_items));
        fout.write(reinterpret_cast<const char*> (&_Vindex), sizeof (_Vindex));
        fout.write(reinterpret_cast <const char*> (_array), sizeof(T)*_items);
    }
    else
        cout <<"Stream open error. \n";
}
template <class T>
void RubberArray<T>::read (ifstream& fin)
{
    if (fin)
    {
      fin.read(reinterpret_cast<char*> (&_items), sizeof (_items));
      fin.read(reinterpret_cast<char*> (&_Vindex), sizeof (_Vindex));
      T* temp = new T[_items];
      fin.read(reinterpret_cast<char*> (temp), sizeof(T) *_items);
      *this = RubberArray<T>(temp,_items,_Vindex);
      delete []temp;
    }
    else
    {
        cout <<"stream open error. \n";
    }
}
#endif // RUBBERARRAY_H_KN
