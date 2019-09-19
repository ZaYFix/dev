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
      
      void distance();
      void milieu();
      
      // Services
      void affiche() const;
};

#endif //POINT_H
