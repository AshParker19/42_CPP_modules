#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), sizeN(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]), sizeN(n) {}

template <typename T>
Array<T>::Array(const Array &other) : elements(NULL), sizeN(0)
{
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this == &other)
        return (*this);
    delete []elements;
    sizeN = other.sizeN;
    elements = new T[sizeN];
    for (size_t i = 0; i < sizeN; i++)
        elements[i] = other.elements[i];
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete []elements;
}

template <typename T>
T &Array<T>::operator[](int index)
{
    if (index < 0 || index >= static_cast<int>(sizeN))
        throw (OutOfBoundException());
    return (elements[index]);
}

template <typename T>
size_t Array<T>::size() const
{
   return (sizeN);
}

template <typename T>
const char *Array<T>::OutOfBoundException::what(void) const throw()
{
    return ("Index out of bounds");
}


#endif