#include "rational.h"
#include "matrix.h"

int main(  )
{	
	rational r( 1, -2);
	std::cout << -r << "\n";
	
	rational r1( 2, 6 );
   	rational r2( 4, 3 ); 
   	rational r3( 5,6 );
   	rational r4( 1, 2 );

   	matrix m1 = { { 2, 3 }, { 4, 6 } };
   	std::cout << m1 << "\n";

   	matrix m2 = { { 5,4 }, { 6, rational(1,2) } }; 
   	std::cout << m2 << "\n";

   	matrix m3 = { { 4,5}, { -1, 2 }};
   	std::cout << m3 << "\n";

   	std::cout << m1. determinant( ) << "\n";

   	std::cout << m1. adjugate( ) << "\n";

   	if( m1.determinant() != 0)
   		std::cout << m1. inverse( ) * m1 << "\n";
   	else
   		std::cout << "determinant is 0\n";
	


   return 0;
}


