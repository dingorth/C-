#include "surface.h"
#include <vector>
void surface::operator = ( const surface& s )
{
	ref = s.ref -> clone();
}

void surface::operator = ( surface&& s )
{
	ref = s.ref -> clone();
}

void surface::operator = ( const surf& s )
{
	ref = s.clone();	
}

void surface::operator = ( surf&& s )
{
	ref = s.clone();
}

std::ostream& operator << ( std::ostream& stream, const surface& s )
{
	s.ref -> print( stream );
	return stream;
}

std::ostream& operator << ( std::ostream& stream,
	const std::vector< surface > & table )
{
	for( size_t i = 0; i < table. size( ); ++ i )
	{
		stream << i << "-th element = \n" << table [i] << "\n";
	}
	return stream;
}

void print_statistics( const std::vector< surface > & table )
{
	double total_area = 0.0;
	double total_circumference = 0.0;

	for( const auto& s : table )
	{
		std::cout << "adding info about " << s << "\n";
		total_area += s. getsurf( ). area( );
		total_circumference += s. getsurf( ). circumference( );
	}
	
	std::cout << "total area is " << total_area << "\n";
	std::cout << "total circumference is " << total_circumference << "\n";
}