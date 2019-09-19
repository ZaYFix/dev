#include <iostream>
#include <cmath> /* pour sqrt */

using namespace std;

#include "Point.h"

// Constructeurs
Point::Point()
{
    x = 0.0;
    y = 0.0;
}

Point::Point(double x = 0.0, double y = 0.0)
{
    this->x = x;
    this->y = y;
}

// Destructeur  
Point::~Point()
{
    cout << "Je suis le destructeur de la classe Point !" << endl;
}

// Accesseurs et mutateurs
double Point::getX() const
{
    return x;
}

double Point::getY() const
{
    return y;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}

/*void Point::distance()
{
    // TO DO
}

void Point::milieu()
{
    // TO DO
}*/


// Services
void Point::affiche() const
{
   cout << "<" << x << "," << y << ">" << endl;
}
