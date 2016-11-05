
#include <fstream>
#include <iostream>
#include <chrono> 
#include <random>

#include "listtest.h"
#include "vectortest.h"

std::list<std::string> vector_to_list( std::vector<std::string> v ){
	std::list<std::string> l;
	for( std::string s : v )
		l.push_back(s);
	return l;
} 

// vector sortuje sie nieznacznie szybciej

int main( int argc, char* argv [] )
{
	for( int k = 1; k <= 3; ++ k ) 
	{


	auto vect = vectortest::randomstrings(5000*k,50);



	auto v = vect;
	

	auto t1 = std::chrono::high_resolution_clock::now( ); 
	vectortest::sort_move( vect );
	auto t2 = std::chrono::high_resolution_clock::now( );

	std::chrono::duration< double > d = ( t2 - t1 );

	auto t3 = std::chrono::high_resolution_clock::now( );
	vectortest::sort_assign( v );
	auto t4 = std::chrono::high_resolution_clock::now( );

	std::chrono::duration< double > d2 = ( t4 - t3 );

	std::cout << "sorting vector took " << d. count( ) << " seconds\n";
	std::cout << "sorting vector 2 took " << d2. count( ) << " seconds\n";

    }

	return 0;
}


