#include "rational.h"
#include <iostream>
#include <stdexcept>
#include <cmath>


// Complete these methods:


/** TODO	


**/

#if 1

int rational::gcd( int n1, int n2 ){
	if( n2==0 )
		return n1;
	else
		return gcd(n2, n1%n2 );
}

void rational::normalize( ){
	if(denum==0)
		throw std::runtime_error( "denum is 0" );

	if(denum < 0){
		num=-num;
		denum=-denum;
	}
	int c=gcd(std::abs(num) , denum);
	num/=c;
	denum/=c;
}

rational operator - ( rational r ){
	r.setNum() = -r.getNum();
	return r;
}

rational operator + ( const rational& r1, const rational& r2 ){
	return  rational( r1.getNum() * r2.getDenum() + r2.getNum() * r1.getDenum(), r1.getDenum() * r2.getDenum() );
}

rational operator - ( const rational& r1, const rational& r2 ){
	return rational( r1.getNum() * r2.getDenum() - r2.getNum() * r1.getDenum(), r1.getDenum() * r2.getDenum() );
}

rational operator * ( const rational& r1, const rational& r2 ){
	return rational(r1.getNum() * r2.getNum(), r2.getDenum() * r1.getDenum() );
}

rational operator / ( const rational& r1, const rational& r2 ){
	return rational(r1.getNum() * r2.getDenum(), r2.getNum() * r1.getDenum() );
}

bool operator == ( const rational& r1, const rational& r2 ){
	return(r1.getNum() == r2.getNum() && r2.getDenum() == r1.getDenum());

}
bool operator != ( const rational& r1, const rational& r2 ){
	return!( r1 == r2 );

}

std::ostream& operator << ( std::ostream& stream, const rational& r ){
	if( r.getDenum()==1 ){
		stream << r.getNum();
		return stream;
	}
	stream << r.getNum() << "/" << r.getDenum();
	return stream;
}

#endif

