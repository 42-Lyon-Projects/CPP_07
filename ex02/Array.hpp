#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
	private:
		T *array;
		unsigned int size;

	public:
		explicit Array();
		explicit Array(unsigned int size);
		Array(const Array &other);
		Array& operator=(const Array& other);
		T operator[](size_t index) const throw (std::exception);
		T &operator[](size_t index) throw (std::exception);
		~Array();
		unsigned int getSize();
};

template<typename T>
Array<T>::Array()
{
	size = 0;
	array = new T[size];
}

template<typename T>
Array<T>::Array(unsigned int size)
{
	this->size = size;
	array = new int[this->size];
}

template<typename T>
Array<T>::Array(const Array &other)
{
	this->size = other.size;
	this->array = new T[this->size];
	for (unsigned int i = 0; i < this->size; ++i)
		this->array[i] = other.array[i];
}


template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	delete [] this->array;
	this->array = new T[other.size()];
	for (unsigned int i = 0; i < other.size; ++i)
		this->array[i] = other.array[i];
	return (*this);
}


template<typename T>
T &Array<T>::operator[](size_t index) throw (std::exception)
{
	if (index < 0 || index >= size)
		throw std::exception();
	return this->array[index];
}

template<typename T>
T Array<T>::operator[](size_t index) const throw (std::exception)
{
	if (index < 0 || index >= size)
		throw std::exception();
	return this->array[index];
}

template<typename T>
Array<T>::~Array()
{
	delete [] this->array;
	std::cout << "Destructor of Array is Called " << std::endl;
}

template<typename T>
unsigned int Array<T>::getSize()
{
	return size;
}




#endif
