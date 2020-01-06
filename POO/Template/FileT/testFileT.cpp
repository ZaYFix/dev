#include <iostream>
#include <exception>
#include "FileT.h"

using namespace std;

int main() 
{
   int n=12, p=15;
   float x=4.25, y=3.5;

   cout << "maxi(n, p) -> " << maxi<int>(n, p) << endl;
   cout << "maxi(x, y) -> " << maxi<float>(x, y) << endl;
   
   return 0;
}
