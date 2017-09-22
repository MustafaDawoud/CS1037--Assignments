#include "SimpleVector.h"
#include <iostream>

SimpleVector::~SimpleVector() {
	//Destructor to that deletes the array in the heap memory 
	delete[] this->_array;
	this->_array = NULL;
}

SimpleVector::SimpleVector(	) {
	//Declaring the default constructor which assigns the capacity to 10 and creates an array size of that
	this->_capacity = 10;
	this->_array = new int[_capacity];
	this->_numElements = 0; //The original number of elements should be 0
}

SimpleVector::SimpleVector(int a) {
	//Declaring an overloaded constructor to accomodate for a specific capacity the user wants
	this->_capacity = a;
	this->_array = new int[_capacity];
	this->_numElements = 0;
}

int SimpleVector::size() {
	//Returns number of filled elements in the array which is represented by _numELements
	return _numElements;
}

void SimpleVector::push_back(int x) {
	//if number of elements is equal to the capacity we would need to make the capacity larger to accomodate for the extra element
	if (this->_numElements == this->_capacity) {
		extend();
	}
	//setting the value inputted by the user at the index of the maximum index + 1 
	_array[_numElements] = x;
	_numElements += 1; // Increasing the value of numElements by 1 so that the array knows that it's supposed to point to the new object
}

void SimpleVector::reverse() {
	//For loop used to copy the last element to a temperary variable, then swap the first value with the last value, 
	//then do the same for the second last value and the second value using the temporary variable, it does so until the 
	//whole array is reversed, runs a number of number of elements/2
	for (int i = 0, j = _numElements - 1; i < j; i++, j--)
	{
		int temp = _array[i];
		_array[i] = _array[j];
		_array[j] = temp;
	}
}

void SimpleVector::set(int x, int i) {
	//Checking if the value of the index where the user wants to set the value is in the range of [natural numbers or 0 and < number of elements]
	if (i < _numElements && i>=0)
		_array[i] = x;
	//if its not in the range, leave the method
	else
		return;
}

void SimpleVector::clear() {
	//making the array think that it doesn't have anymore elements
	this->_numElements = 0;
}

int SimpleVector::empty() {
	//returning specified value based on whether the array's number of elements is empty or not
	if (_numElements == 0)
		return 1;
	return 0;
}

void SimpleVector::pop_back() {
	//Special case if the number of elements in the array is 0, it cannot popback anything
	if (_numElements == 0)
		return;
	//otherwise, lower the number of elements by 1 thus making the array think that it doesn't own that value anymore
	_numElements -= 1;

}

int SimpleVector::insert(int x, int i) {
	//Returns to the main is the index that should be inserted is outside the range of the number of elements
	//(should be no gaps between insert index and number of elements)
	if (i<0 || i>_capacity - 1 || i >= _numElements)
	{
		return 1;
	}

	else
	{
		//Since we are inserting a new element we need to make the capacity and the number of elements bigger
		extend();
		_numElements++;
		//for loop used to create garbage space at the insert index
		for (int j = _numElements; j > i; j--)
		{
			_array[j] = _array[j - 1];
		}
	}
	//inserting the value that the user wants to have inputted
	_array[i] = x;
	
	return 0;
	
}

void SimpleVector::extend() {
	//increasing the capacity by 2 in the memory
	_capacity = _capacity * 2;
	//Creating a new array to hold the values of the elements in the new array
	int *temp = new int[_numElements];
	//Copying the elements to the temporary array
	for (int i = 0; i < _numElements; i++)
		temp[i] = _array[i];
	//Creating a dynamic array that is with size of the new capacity
	_array = new int[_capacity];
	//Copying back the values from the temporary array to the newly sized array
	for (int i = 0; i < _numElements; i++)
		_array[i] = temp[i];
}

int& SimpleVector::operator[](int i) {
	if (i < 0 || i >= _numElements) {
		std::cout << "Index out of bounds" << std::endl;
		return _array[0];
	}
	return _array[i];
}
const int& SimpleVector::operator[](int i) const {
	if (i < 0 || i >= _numElements) {
		std::cout << "Index out of bounds" << std::endl;
		return _array[0];
	}
	return _array[i];
}

void SimpleVector::print() {
	for (int i = 0; i < _numElements; i++) {
		std::cout << "Element at position " << i << " " << _array[i] << std::endl;
	}
}