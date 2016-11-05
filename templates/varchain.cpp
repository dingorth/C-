
#include "varchain.h"
#include <algorithm>


std::ostream& operator << ( std::ostream& out, const powvar & p )
{
   if( p.n == 0 )
   {
      out << "1"; // Should not happen, but we still have to print something.
      return out;
   }

   out << p.v;
   if( p.n == 1 )
      return out;

   if( p.n > 0 )
      out << "^" << p.n;
   else
      out << "^{" << p.n << "}";
   return out;
}


std::ostream& operator << ( std::ostream& out, const varchain& c )
{
   if( c. isunit( ))
   {
      out << "1";
      return out;
   }

   for( auto p = c. repr. begin( ); p != c. repr. end( ); ++ p )
   {
      if( p != c. repr. begin( ))
         out << ".";
      out << *p;
   }

   return out;
}


int varchain::power( ) const 
{
   int p = 0;
   for( auto pv : repr )
      p += pv. n;
   return p;
}


void varchain::normalize()
{
   if( isunit() ) return;
   // sorting
   std::sort( repr.begin(), repr.end(), 
      [] ( const powvar &a, const powvar &b ) -> bool { return a.v < b.v; } );

   // merging

   for( auto i = repr.begin(); i != repr.end() - 1; )
   {
      if( (i+1) -> v == i -> v )
      {
         (i+1) -> n += i -> n;
         i = repr.erase(i); 
      }
      else 
         i++;
   }

   // deleting zeros
   for( auto i = repr.begin(); i != repr.end();  )
      if( i -> n == 0 ) 
         i = repr.erase(i);
      else 
         ++i;
}

varchain operator * ( varchain c1, const varchain& c2    )
{
   c1.repr.insert( c1.repr.end(), c2.repr.begin(), c2.repr.end() );
   c1.normalize();
   return c1;
}

/*
int main()
{
   varchain test( { {"x",2}, {"x",-2}  } );

   varchain a({ {"x",2}, {"y",4}, {"x",3} } );

   varchain b( { {"x",3}, {"z",3}, {"y",-4} } );

   std::cout << a;

   return 0;
}*/