#include <iostream>

using namespace std;

template<class T, int size = 100>
class Array 
{
   private:
      T A[size];
   public:
      T& operator[](int index);
      int length() const { return size; }
};

template<class T, int size>
T& Array<T, size>::operator[](int index) 
{
   if(index >= 0 && index < size)
      return A[index];
   else cerr << "Index out of range" << endl;         
}

int main() 
{
   Array<int> ia1;
   
   ia1[0] = 1;
   cout << ia1[0] << endl;
   cout << ia1.length() << endl;
}
