#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *array, size_t size, void(*f)(T const &))
{
	if (!array || !size || !f)
		return;
	for(size_t i = 0; i < size; i++)
		f(array[i]);
}

#endif