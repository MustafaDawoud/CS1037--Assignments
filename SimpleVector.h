#pragma once
#ifndef SIMPLVECTOR_H
#define SIMPLVECTOR_H
#include <cstddef> //Including NULL

class SimpleVector {
	private:
		//Private memebers defined
		int *_array;
		int _capacity;
		int _numElements;
		void extend();

	public:
		//Prototyping Member Functions
		int size();
		void push_back(int x);
		void reverse();
		void set(int x, int i);
		void clear();
		int empty();
		void pop_back();
		int insert(int x, int i);
		void print();
		int& operator[](int i);
		const int& operator[](int i) const;
				
		//Constructors
		SimpleVector();
		SimpleVector(int a);

		//Destructor
		~SimpleVector();
};
#endif