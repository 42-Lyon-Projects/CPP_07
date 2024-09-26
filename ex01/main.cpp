#include <iostream>

#include "iter.hpp"
#include "cmath"

template <typename V>
static void expArray(V &v)
{
	v = exp(v);
	std::cout << "Exp Value: " << v << '\n' << std::flush;
}

int main()
{
	{
		int *integerArray = new int[5];
		integerArray[0] = 1;
		integerArray[1] = 2;
		integerArray[2] = 3;
		integerArray[3] = 4;
		integerArray[4] = 5;
		iter(integerArray, 5, expArray);
		std::cout << std::endl;
		delete [] integerArray;
	}
	{
		double *decimalArray = new double[5];
		decimalArray[0] = 1.5;
		decimalArray[1] = 4.3;
		decimalArray[2] = 9.2;
		iter(decimalArray, 3, expArray);
		delete[] decimalArray;
	}
}