#include <iostream>
#include<list>
#include<string>
#include<cstdlib>
#include<vector>


// Declaration

template <class T> 
class SafeArray {
 public:
   SafeArray<T> (int firstInvalidIndex);
   SafeArray<T> (int firstValidIndex, int firstInvalidIndex);
   T& operator[](int ndx);
   int length();
   
// copy constructor:
   SafeArray<T>( const SafeArray& obj);
// assignment operator:
   SafeArray<T>& operator=(const SafeArray<T>& other);


// destructor:
   ~SafeArray<T>();


 private:
   int firstValid;
   int firstInvalid;
   T *A;
};


// Implementation
template<class T>
SafeArray<T> :: SafeArray(int firstInvalidIndex)
{
	firstValid = 0;
	firstInvalid = firstInvalidIndex;	
	int size = firstInvalid - firstValid;

	A = new T[size];

}

template<class T>
SafeArray<T> :: SafeArray(int firstValidIndex, int firstInvalidIndex)
{
	
	firstValid = firstValidIndex;
	firstInvalid = firstInvalidIndex;
	int size = firstInvalid - firstValid;

	A = new T[size];
}

template<class T>
SafeArray<T>::SafeArray(const SafeArray<T>& obj)
{
	std::cout << "Copy constructor called!\n";
	
	firstInvalid = obj.firstInvalid;
	firstValid = obj.firstValid;

	int size = firstInvalid - firstValid;

	A = new T[size];

	for (int i = 0; i<size; i++)
	{
		A[i] = obj.A[i];

	}

	//A = obj.A;
}


template<class T>
 SafeArray<T> &SafeArray<T>:: operator=(const SafeArray<T>& other)
{
	std::cout << "Assignment operator invoked!\n";
	delete[]A;

	firstInvalid = other.firstInvalid;
	firstValid = other.firstValid;
	T* A;

	int size = other.firstInvalid - other.firstValid;

	A = new T[size];

	
	for(int i=0; i<size;i++)
	{
		A[i]=other.A[i];
		
	}

    return *this;

 };


template<class T>
T &SafeArray<T>::operator[](int ndx)
{
	if (ndx < firstValid)
	{
		std::cout << "SafeArray index " << ndx << " out of bounds: too small \n";
		exit(1);
	}
	if (ndx >= firstInvalid)
	{
		std::cout << "SafeArray index" << ndx << " out of bounds : too large \n";
		exit(1);
	}
	
	return A[ndx];
}

template<class T>
SafeArray<T>::~SafeArray()
{
	delete[]A;
}


template <class T>
int SafeArray<T>::length()
{
	return firstInvalid-firstValid;
}
