#include <iostream>

using namespace std;

template<class T>
class Array 
{
   private:
      enum { size = 10 };
      T A[size];
   public:
      T& operator[](int index)
      {
         if(index >= 0 && index < size)
            return A[index];
         else cerr << "Index out of range" << endl;         
      }
      int length() const { return size; }
};


class Number 
{
   private:
      float f;
      
   public:
      Number(float ff = 0.0f) : f(ff) { }
      Number& operator=(const Number& n) {
         f = n.f;
         return *this;
      }
      operator float() const { return f; }
      friend ostream& operator<<(ostream& os, const Number& x) { return os << x.f; }
};


int main() 
{
   Array<Number> fa;
   
   cout << fa[0] << endl;
   fa[0] = 1.5;
   cout << float(fa[0]) << endl;
   cout << fa.length() << endl;
}
