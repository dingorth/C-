#include "stack.h"
#include <iostream>


/**

**/


int main(){

	stack s1 = { 1, 2, 3, 4, 5 };
	stack s2 = { 6, 7, 8, 9, 10 };

	stack s3=s1+s2;

	std::cout << "s1 " << s1 << "\ns2 " << s2 << "\ns3 " << s3 <<"\n";

	return 0;
}