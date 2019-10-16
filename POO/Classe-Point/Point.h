#ifndef POINT_H
#define POINT_H

class Point 
{
   private:
      double x;
      double y;
      
   public:
      // Constructeurs
      Point();
      Point(double x, double y);
      
      // Destructeur
      ~Point();  
      
      // Accesseurs et mutateurs
      double getX() const;
      double getY() const;
      
      void setX(double x);
      void setY(double y);
      
      double distance(const Point &PointA);
      Point milieu(const Point &PointA);
      
      // Services
      void affiche() const;
};

#endif //POINT_H
