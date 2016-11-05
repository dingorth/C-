#include <iostream>
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "surface.h"
#include <vector>

int main()
{

	rectangle a;
	circle b;
	triangle c;

	std::vector< surface > test = { a, b, c };

	print_statistics(test);

	return 0;
}
