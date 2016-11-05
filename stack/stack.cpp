#include <stdexcept>
#include "stack.h"

void stack::ensure_capacity( size_t c )
{
	if( current_capacity < c )
	{
		// New capacity will be the greater of c and
		// 2 * current_capacity.
		if( c < 2 * current_capacity )
			c = 2 * current_capacity;

		double* newtab = new double[ c ];
		for( size_t i = 0; i < current_size; ++ i )
			newtab[i] = tab[i];

		current_capacity = c;
		delete[] tab;
		tab = newtab;
	}
}

void stack::operator = ( const stack& s ) {
	if(this != &s ){
		ensure_capacity(s.current_size);// nieoptymalne
		// current_capacity=s.current_capacity;
		current_size=s.current_size;
		for( size_t i =0; i< s.current_size; i++)
			tab[i]=s.tab[i];
	}
}

void stack::push( double d ) {
	ensure_capacity ( current_size + 1 );
	tab[current_size++]=d;
}

void stack::pop( ) {
	if( current_size > 0 )
		current_size--;
	else
		throw std::runtime_error( "stack is empty" );
}

void stack::reset( size_t s ) {
	current_size = s;
}
double& stack::top( ){
	if( current_size > 0 )
		return tab[current_size-1];
	throw std::runtime_error( "stack is empty" );

}
double stack::top( ) const{
	if( current_size > 0 )
		return tab[current_size-1];
	throw std::runtime_error( "stack is empty" );

}

std::ostream& operator << ( std::ostream& stream, const stack& s ){
	if( s.empty() )
		stream << "Stack is empty.";
	else
		for(size_t i = 0; i < s.current_size; i++)
			stream << s.tab[i] << " ";
	return stream;
}


//lista4
double stack::operator [] ( size_t i ) const{
	if( i > size()-1 )
		throw std::runtime_error( "iterator out of array" );
	if( size() == 0 )
		throw std::runtime_error( "array is empty" );
	return tab[size()-i-1];

}
double & stack::operator [] ( size_t i ){
	if( i > size()-1 )
		throw std::runtime_error( "iterator out of array" );
	if( size() == 0 )
		throw std::runtime_error( "array is empty" );
	return tab[size()-i-1];
}

void stack::operator += ( double d ){
	push(d);
}
void stack::operator += ( const stack& s ){
	ensure_capacity(current_size + s.current_size );
	for( size_t i=0; i<s.current_size; i++)
		tab[current_size+i]= s.tab[i];
	current_size+=s.current_size;
}

stack operator + ( stack s1, const stack& s2 ){
	// return s1 += s2; //tak nie mozna
	s1+=s2;
	return s1;
}
