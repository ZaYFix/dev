#include <iostream>
#include <cmath> /* pour sqrt */

using namespace std;

#include "Point.h"

// Constructeurs
Point::Point():x(0.0),y(0.0)
{
    
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
    cout << "L'addresse mémoire est: " << this << endl;
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

double Point::distance(const Point &PointB)
{
    double xPointA = this -> x;
    double yPointA = this -> y;
    
    double xPointB = PointB.getX();
    double yPointB = PointB.getY();
    
    double distance = sqrt(pow(xPointA - xPointB, 2) + pow(yPointA - yPointB,2));
    
    return distance;
}

Point Point::milieu(const Point &PointB)
{
    double xPointA = this -> x;
    double yPointA = this -> y;
    
    double xPointB = PointB.getX();
    double yPointB = PointB.getY();
    
    const double xPointMilieu = (xPointA + xPointB)/2;
    const double yPointMilieu = (yPointA + yPointB)/2; 
    
    Point pointMilieu(xPointMilieu, yPointMilieu);
    
    return pointMilieu;
}


// Services
void Point::affiche() const
{
   cout << "<" << x << "," << y << ">" << endl;
}
