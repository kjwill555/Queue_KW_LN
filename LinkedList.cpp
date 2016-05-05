#ifndef _LINKED_LIST
#define _LINKED_LIST
#include "Node.cpp"
#include <iostream>
#include <string>

template <class T>
class LinkedList{
private:
	Node<T> header; //header node, cotains pointer to first node. data is garbage value
	Node<T>* first; //address of the first node in the list
	Node<T>* last; //address of the last node in the list
	int length;
protected: //these are protected so that inherited classes only use methods useful to the class
	Node<T>* getFirst() { return first; }
	Node<T>* getLast() { return last; }
	void insertAt(Node<T>&, int);
	void pushFront(Node<T>&);
	T popFront();
	void pushBack(Node<T>&);
	T popBack();
	void deleteAt(int);
	void printList();
	int find(T);
	int getLength() { return length; }
public:
	LinkedList();
};

//Default constructor
//length is set to zero
//first and last set to the header's address
template <class T>
LinkedList<T>::LinkedList() {
	length = 0;
	first = &header;
	last = &header;
}

//Add a node to the front of the list
template <class T>
void LinkedList<T>::pushFront( Node<T> &node) {
	if (length == 0) { //node will be first in list
		first = &node; //node will be first and last for now
		last = &node;
		header.setNext(first);
		length++;
	}
	else {
		node.setNext(first); //next node will be the current first node
		first = &node;
		header.setNext(first);
		length++;
	}
}

//Remove the first node from the list and return its data
template <class T>
T LinkedList<T>::popFront() {
	if (length > 0) {
		T data = first->getData();
		Node<T>* next = first->getNext();
		first->setNext(nullptr);
		header.setNext(next);
		first = header.getNext();
		length--;
		return data;
	}
	else {
		throw std::underflow_error("List is already empty");
	}
}

//Add a node to the end of the list
template <class T>
void LinkedList<T>::pushBack(Node<T> &node) {
	if (length == 0) { //node will be the only one in the list
		first = &node;
		last = &node;
		header.setNext(&node);
		length++;
	}
	else {
		last->setNext(&node);
		last = &node;
		last->setNext(nullptr);
		length++;
	}
}

//Delete the last node from the list and return its data
template <class T>
T LinkedList<T>::popBack() {
	if (length > 0) {
		T data = last->getData();
		Node<T>* secondToLast=&header;
		while (secondToLast->getNext() != last) {
			secondToLast = secondToLast->getNext();
		}
		secondToLast->setNext(nullptr);
		last = secondToLast;
		length--;
		return data;
	}
	else {
		throw std::underflow_error("List is already empty");
	}
}

//Print the data contained in all nodes in the list
//If the list is empty, a proper message is shown
template <class T>
void LinkedList<T>::printList() {
	if (length != 0) {
		Node<T>* nextNode = first;
		while (nextNode != nullptr) {
			std::cout << nextNode->getData() << endl;
			nextNode = nextNode->getNext();
		}
	}
	else {
		std::cout << "List is empty" << endl;
		return;
	}
}

//Insert a node anywhere in the list
//indexes start at 0
template <class T>
void LinkedList<T>::insertAt(Node<T>& n, int index) {
	if (index == 0) { //just add it to the front
		pushFront(n);
	}
	else if (index == length) { //just add it to the back
		pushBack(n);
	}
	else if (index<0 || index>length) { //index is outside of valid range
		std::cout << "Invalid index" << endl;
		return;
	}
	else {
		Node<T>* currentAtIndex=first;
		for (int i = 0; i < index-1; i++) { //find the current node at that index
			currentAtIndex = currentAtIndex->getNext();
		}
		n.setNext(currentAtIndex->getNext());
		currentAtIndex->setNext(&n);
		length++;
	}
}

//Delete a node at a specific index
template <class T>
void LinkedList<T>::deleteAt(int index) {
	if (index == 0) { //just delete the front
		popFront();
	}
	else if (index == length-1) { //just delete the back
		popBack();
	}
	else if (index < 0 || index >= length) { //index is not valid
		std::cout << "Invalid index" << endl;
		return;
	}
	else {
		Node<T>* currentAtIndex = first;
		for (int i = 0; i < index; i++) { //find the desired node to be deleted
			currentAtIndex = currentAtIndex->getNext();
		}
		Node<T>* before = first;
		while (before->getNext() != currentAtIndex) { //find the node before the one to be deleted
			before = before->getNext();
		}
		before->setNext(currentAtIndex->getNext());
		currentAtIndex->setNext(nullptr);
		length--;
	}
}

//Returns the index of the node containing the inputted data
//If no nodes contain the data, -1 will be returned
template <class T>
int LinkedList<T>::find(T data) {
	Node<T>* currentAtIndex = first;
	for (int i = 0; i < length; i++) {
		if (currentAtIndex->getData() == data) {
			return i;
		}
		currentAtIndex = currentAtIndex->getNext();
	}
	return -1;
}
#endif