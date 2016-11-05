#ifndef TRIANGLE_INCLUDED
#define TRIANGLE_INCLUDED 1

#include "surf.h"
#include <cmath>

struct triangle : public surf
{
   double x1, y1;
   double x2, y2;
   double x3, y3;


   double area( ) const override;
   double circumference( ) const override;
   triangle* clone( ) const & override;
   triangle* clone( ) && override;
   void print( std::ostream& ) const override;

   triangle( )
   : x1{0}, y1{0}, x2{1}, y2{0}, x3{0}, y3{1}
   {}

   triangle( double x1, double y1, double x2, double y2, double x3, double y3 )
   : x1{x1}, y1{y1}, x2{x2}, y2{y2}, x3{x3}, y3{y3}
   {}


};

#endif