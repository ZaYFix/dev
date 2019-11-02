#ifndef POINT_H
#define POINT_H

class Point 
{
   private:
      double x,y;
      static int nbPoints;
      
   public:
      static int compte();
      static double distance(Point p1,Point p2);
      static Point milieu(Point p1,Point p2);
      
      // Constructeurs
      Point();
      Point(double x, double y);

      // Destructeur
      ~Point();

      void affiche() const;  
};

#endif //POINT_H
