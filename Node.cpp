#ifndef _NODE
#define _NODE

template <class T>
class Node {
private:
	T data; //data contained in the node
	Node<T>* next; //pointer to the next node in the list
public:
	Node();
	Node(T);
	Node(T, Node<T>*);
	void setData(T);
	T getData();
	void setNext(Node<T>*);
	Node<T>* getNext();
};

//Default constructor
//next is set to null by default
//data will remain uninitialized value (type dependent)
template <class T>
Node <T>::Node() {
	next = nullptr;
}

//Allows user to initiliaze node with data
//next set to null by default
template <class T>
Node <T>::Node(T newData) {
	data = newData;
	next = nullptr;
}

//Allows user to initilize both attributes
template <class T>
Node <T>::Node(T newData, Node<T>* newPointer) {
	data = newData;
	next = newPointer;
}

//sets the data contained within the node
template <class T>
void Node <T>::setData(T newData) {
	data = newData;
}

//returns the data in the node
template <class T>
T Node<T>::getData() {
	return data;
}

//sets the pointer to the next node
template <class T>
void Node<T>::setNext(Node<T>* newPointer) {
	next = newPointer;
}

//returns the address of the next node
template <class T>
Node<T>* Node<T>::getNext() {
	return next;
}
#endif