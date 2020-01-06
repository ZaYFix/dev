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

template<class T>
T& Array<T>::operator[](int index) 
{
   if(index >= 0 && index < size)
      return A[index];
   else cerr << "Index out of range" << endl;         
}

int main() 
{
   Array<float> fa;
   
   fa[0] = 1.414;
   cout << fa[0] << endl;
}
