
#include "varchain.h"
#include "polynomial.h"
#include "bigint.h"
#include "rational.h"


template< typename N >
polynomial< N > exptaylor( unsigned int n )
{
   varchain v;

   N fact = 1;

   polynomial< N > result;
   for( unsigned int i = 0; i < n; ++ i )
   {
      result[v] += fact;
      v = v * powvar( "x" );
      fact = fact / (i+1);
   }

   return result;
}

int main( int argc, char* argv [] )
{
   polynomial< rational > pol;

   int N = 40;

   pol[ { } ] = 1;
   pol[ { "x" } ] = rational( 1, N ); 

   std::cout << pol << "\n";
   polynomial< rational > res = 1;
 
   for( int i = 0; i < N; ++ i )
      res = res * pol;

   // std::cout << "rsult = " << res << "\n";

   // std::cout << " taylor expansion = " << exptaylor<rational>(20) << "\n";

   std::cout << "difference = " ;  
   std::cout << res - exptaylor<rational> ( 40 ) << "\n";
 
   return 0;
}


