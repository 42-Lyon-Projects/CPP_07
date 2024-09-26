#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
static void iter(T *array, int length, void (*pfunction)(T&))
{
	for(int i = 0; i < length; i++)
	{
		T element = array[i];
		pfunction(element);
	}
}

#endif
