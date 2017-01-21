#include "CList.h"

template<class T>
Node<T>::Node(T value) : value(value)
{
}

template<class T>
Node<T>::Node(Node & pcOther)
{
	Node<T> *pc_res = new Node<T>(pcOther.getValue());

	pc_res->setNext(new Node<T>(*pcOther.getNext()));
	pc_res->setPrevious(new Node<T>(*pcOther.getPrevious()));

	return(*pc_res);
}

template<class T>
T Node<T>::getValue()
{
	return value;
}

template<class T>
void Node<T>::setNext(Node * next)
{
	this->next = next;
}

template<class T>
void Node<T>::setPrevious(Node * previous)
{
	this->previous = previous;
}

template<class T>
Node<T> * Node<T>::getNext()
{
	return next;
}

template<class T>
Node<T> * Node<T>::getPrevious()
{
	return previous;
}

template<class T>
Node<T>::~Node()
{
	delete previous;
	delete next;
}



template<class T>
int CList<T>::getSize() const
{
	return size;
}

template<class T>
T CList<T>::getNodeValue(int index)
{
	if (index > size - 1)
		throw std::out_of_range("Current index: " + std::to_string(index) + "Current size: " + std::to_string(size));

	Node<T>* currentNode = head;
	for (int i = 0; i != index; i++)
	{
		currentNode = currentNode->getNext();
	}
	return (*currentNode);
}

template<class T>
void CList<T>::add(T value)
{
	Node<T>* currentNode;
	currentNode = head;
	while(currentNode!=nullptr)
		currentNode = currentNode->getNext();

	currentNode=new Node<T>(value); 

	/*if(head!=nullptr)
		currentNode = head;

	if(currentNode!=nullptr)
	while (currentNode->getNext() != nullptr)
		currentNode = currentNode->getNext();

	currentNode->setNext(new Node<T>(value));*/

	size++;
}
