#pragma once
#include "LinkedList.h"


template <class T>

class Queue {
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	int size()const { return m_container.getLength(); }
	void enqueue(T k);
	T dequeue();
	T peek()const;
	T findMax() {
		T max = dequeue();
		enqueue(max);
		unsigned int size = m_container.m_size;
		m_container.m_size -= 1;
		for (; m_container.m_size >= 1; m_container.m_size -= 1) {
			T val = dequeue();
			if (val > max)
				max = val;
			enqueue(val);
		}
		m_container.m_size = size;
		return max;
	}
private:
	List<T> m_container;

};
template <class T>
Queue<T>::Queue() {}

template <class T>
Queue<T>::~Queue() {}

template <class T>
bool Queue<T>::isEmpty() const {
	return m_container.isEmpty();
}
template <class T>
void Queue<T>::enqueue(T  k) {
	m_container.insert(m_container.getLength()+1, k);
}

template <class T>
T Queue<T>::dequeue() {
	return m_container.remove(1);
}

template <class T>
T Queue<T>::peek() const {
	return m_container.retrieve(1);
}