#include "fifteen.h"


std::ostream& operator << ( std::ostream& stream, const fifteen& f )
{
   for(size_t i = 0; i < f.dimension; i++ )
   {
      for(size_t j = 0; j < f.dimension; j++ )
         stream << std::setw(f.width) << f.table[i][j] << " ";
      stream << "\n";
   }
   return stream;
}
         
// chyba tak
bool fifteen::issolved( ) const
{
   size_t number = 1;
   for(size_t i=0; i<dimension; i++)
      for(size_t j=0; j<dimension && number != dimension*dimension; j++, number++)
         if(table[i][j] != number)
            return false;
   return true;
}  

bool fifteen::equals( const fifteen& other ) const
{
   for(size_t i=0; i< dimension; i++)
      for(size_t j=0; j<dimension; j++)
         if( table[i][j] != other.table[i][j] )
            return false;
   return true;
}

std::pair< size_t, size_t > fifteen::solvedposition( size_t val )
{
   if( val == 0 )
      return std::make_pair( dimension-1, dimension-1 );  
   return std::make_pair( (val-1) / dimension , (val-1) % dimension );
}

void fifteen::makemove( move m )
{
   size_t x = open_i;
   size_t y = open_j;

   switch (m) {
      case move::left:
         if (y == 0) throw illegalmove(m);
         else {
            std::swap(table[x][y], table[x][y-1]); 
            open_j -= 1;
         }
         break;
      case move::up:
         if (x == 0) throw illegalmove(m);
         else {
            std::swap(table[x][y], table[x-1][y]);
            open_i -= 1;
         }
         break;
      case move::down:
         if (x == dimension-1) throw illegalmove(m);
         else {
           std::swap(table[x][y], table[x+1][y]);
           open_i += 1;
         }
         break;
      case move::right:
         if (y == dimension-1) throw illegalmove(m);
         else {
           std::swap(table[x][y], table[x][y+1]);
           open_j += 1;
         }
         break;
   }
}

size_t fifteen::distance( ) const
{
   size_t distance=0;
   for(size_t i=0; i< dimension; i++)
      for(size_t j=0; j<dimension; j++)
      {  
         auto solved_pos = solvedposition(table[i][j]);
         distance += abs(solved_pos.first - i) + abs(solved_pos.second - j);
      }
   return distance;
}

size_t fifteen::hashvalue( ) const
{
   size_t hash=0;
   size_t p = 100000007;

   for(size_t i=0; i< dimension; i++)
      for(size_t j=0; j<dimension; j++)
      {
         size_t tmp = table[i][j];
         for(size_t z=0; z < i*dimension + j + 1; z++)
            tmp *= 17;
         hash += tmp;
      }

   return hash % p; 
 }






