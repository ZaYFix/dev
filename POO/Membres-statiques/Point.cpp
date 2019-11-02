#include <iostream>
#include <math.h>

using namespace std;

#include "Point.h"

int Point::nbPoints = 0; // initialisation d’un membre statique

Point::Point() // Constructeur
{
    x = 0.;
    y = 0.;
    nbPoints++; // un objet Point de plus
}

Point::Point(double x, double y) // Constructeur
{
    this->x = x;
    this->y = y;
    nbPoints++; // un objet Point de plus
}

Point::~Point() // Destructeur
{
    nbPoints--; // un objet Point de moins
}

// je retourne le nombre d’objets Point existants à un instant donné
int Point::compte()
{
return nbPoints;
}

double Point::distance(Point p1,Point p2)
{
    double distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y,2));
    
    return distance;
}

Point Point::milieu(Point p1,Point p2)
{
    const double xPointMilieu = (p1.x + p2.x)/2;
    const double yPointMilieu = (p1.y + p2.y)/2; 
    
    Point pointMilieu(xPointMilieu, yPointMilieu);
    
    return pointMilieu;
}


// Services
void Point::affiche() const
{
   cout << "<" << x << "," << y << ">" << endl;
}