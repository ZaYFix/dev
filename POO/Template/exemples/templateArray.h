#ifndef _TEMPLATEARRAY_H_
#define _TEMPLATEARRAY_H_

#include <iostream>

using namespace std;

template<class T>
class Array 
{
   private:
      enum { size = 100 };
      T A[size];
   public:
      T& operator[](int index);
};

#include "templateArray.tcc"

#endif
