#ifndef FILET_H
#define FILET_H

#include <iostream>

using namespace std;

template<class T> T maxi(T a, T b)
{
      if(a > b)
        return a;
      else  
        return b;
}

#include "FileT.tcc"

#endif

