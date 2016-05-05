#ifndef _QUEUE
#define _QUEUE
#include "LinkedList.cpp"

template <class T>
class Queue : public LinkedList<T> {
public:
	Queue() {};
	void enque(Node<T>&);
	T deque();
	T front();
	T rear();
	bool isEmpty();
	int count();
	void clear();
	void printQueue();
};

template <class T>
void Queue<T>::enque(Node<T>& n) {
	pushBack(n);
}

template <class T>
T Queue<T>::deque() {
	try {
		return popFront();
	}
	catch (std::underflow_error& e) {
		std::cout << e.what() << endl;
	}
}

template <class T>
T Queue<T>::front() {
	return getFirst()->getData();
}

template <class T>
T Queue<T>::rear() {
	return getLast()->getData();
}

template <class T>
bool Queue<T>::isEmpty() {
	return (getLength() == 0);
}

template <class T>
int Queue<T>::count() {
	return getLength();
}

template <class T>
void Queue<T>::clear() {
	int len = getLength();
	for (int i = 0; i < len; i++) {
		popFront();
	}
}

template <class T>
void Queue<T>::printQueue() {
	if (getLength() > 0) {
		std::cout << "Front of queue" << endl;
		printList();
		std::cout << "Rear of queue" << endl;
	}
	else {
		std::cout << "Queue is empty" << endl;
	}
}
#endif