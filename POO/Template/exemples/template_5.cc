#include <iostream>

using namespace std;

template<class T>
class Pile
{
   private:
      enum { size = 10 };
      T stack[size];
      int top;
      
   public:
      Pile() : top(0) {}
      void push(const T& i) {
         if(top < size)
            stack[top++] = i;
         else cerr << "Too many push()es" << endl;
      }
      T pop() {
         if(top > 0)
               return stack[--top];
         else  cerr << "Too many pop()s" << endl;
      }
      int length() const { return size; }
      class PileIter;
      friend class PileIter;

      class PileIter
      {
         private:   
            Pile& s;
            int index;
            
         public:
            PileIter(Pile& is) : s(is), index(0) {}
            T operator++() { // Prefix
               if(index < s.top) 
                     return s.stack[++index];
               else  cerr << "iterator moved out of range" << endl;
            }
            T operator++(int) { // Postfix
               if(index < s.top) 
                     return s.stack[index++];
               else  cerr << "iterator moved out of range" << endl;
            }
      };
};

int main() 
{
   Pile<float> is;
   for(int i = 0; i < 5; i++)
      is.push(i*1.5);
   
   // Traverse avec un itérateur:
   Pile<float>::PileIter it(is);
   for(int j = 0; j < 5; j++)
      cout << it++ << endl;

   cout << is.length() << endl;
}
