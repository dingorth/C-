#include "listtest.h"

#include <random>
#include <chrono>
#include <algorithm>


std::list<std::string> listtest::readfile( std::istream& input )
{
	std::list<std::string> l;

   std::string str;
   char tmp;
   while(  ( tmp=input.get() ) && input.good() )
   {
      if(  ispunct( tmp ) || isspace( tmp ) ){
         if(!str.empty()){
            l.push_back( str );
            str.clear();
         }
      }
      else
         str += tmp;
   }
   return l;
}

std::list<std::string> listtest::randomstrings( size_t nr, size_t s )
{
	static std::default_random_engine gen( 
      std::chrono::system_clock::now( ). time_since_epoch( ). count( ) );
         // Narrowing long int into int, but that is no problem.

   static std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012345689";
   static std::uniform_int_distribution<int> distr( 0, alphabet. size( ) - 1);
      // More narrowing.

   std::list< std::string > res;

   for( size_t i = 0; i < nr; ++ i )
   {
      std::string rand;
      for( size_t j = 0; j < s; ++ j )
      {
         rand. push_back( alphabet[ distr( gen ) ] );  
      }

      res. push_back( std::move( rand ));
   }
   return res;
}
 
void listtest::sort_assign( std::list< std::string > & l )
{
	for( auto j = l.begin(); j != l.end(); ++ j )
      for( auto i = l.begin(); i != j; ++ i )
      {
         if( *i > *j )
         {  
            std::string s = *i;
            *i = *j;
            *j = s;
         }
      }
}

void listtest::sort_move( std::list< std::string > & l )
{
	for( auto j = l.begin(); j != l.end(); ++ j )
      for( auto i = l.begin(); i != j; ++ i )
      {
         if( *i > *j )
         {  
            std::swap(*i, *j);
         }
      }
}

void listtest::sort_std( std::list< std::string > & l )
{
	l.sort();
}

std::ostream& operator << ( std::ostream& out, const std::list< std::string > & l )
{
	out << "{"; // not for each| should compare
   for( const std::string& s : l ){
      if( s!= l.front() )
         out << ",";
      out << " " << s;
   }
   out << " }";
   return out;
}

