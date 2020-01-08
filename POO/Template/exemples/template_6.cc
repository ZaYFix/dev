#include <iostream>
#include <cstring>
using namespace std;

template<class T> T mini(T a, T b)
{
      if(a < b)
            return a;
      else  return b;
}

template<class T> T mini(T a, T b, T c)
{
      return mini(mini(a, b), c);
}

template <> const char *mini(const char * a, const char * b)
{
    return (strcmp( a, b ) < 0) ? a : b;
}


int main() 
{
   int n=12, p=15, q=2;
   float x=3.5, y=4.25, z=0.25;

   cout << "mini(n, p) -> " << mini(n, p) << endl;
   cout << "mini(n, p, q) -> " << mini(n, p, q) << endl;
   cout << "mini(x, y) -> " << mini(x, y) << endl;
   cout << "mini(x, y, z) -> " << mini(x, y, z) << endl;
   
   cout << "mini(n, p) -> " << mini<float>(n, q) << endl;
   
   cout << "mini(n, p) -> " << mini("hello", "wordl") << endl;
}
