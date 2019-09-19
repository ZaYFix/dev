#include <iostream>
using namespace std;

int main() 
{
    int tempMin = 0;
    int tempMax = 0;
    int temperature = 0;
    
    cin >> tempMin >> tempMax;
    
    if ( tempMin > tempMax)
    {
        temperature = tempMin;
        tempMin = tempMax;
        tempMax = temperature;
    }
    
    for (int i=tempMin;i<=tempMax;i++)
    {
        cout << i << endl;
    }
    return 0;
}
