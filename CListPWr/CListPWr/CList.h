#pragma once
#include <stdexcept>
#include <string>

template <class T>
class Node
{
private:
	T value;
	Node* previous=nullptr;
	Node* next=nullptr;

public:
	Node(T value);
	Node(Node &pcOther);
	T getValue();
	void setValue(T value);
	void setNext(Node* next);
	void setPrevious(Node* previous);
	Node* getNext();
	Node* getPrevious();
	~Node();
};

template <class T>
class CList
{
private:
	Node<T>* head=nullptr;
	int size=0;

public:
	CList();
	CList(std::initializer_list<T> vInitList);
	int getSize() const;
	T get(int index);
	void add(T value);
	void add(T value, int index)=delete;
	void set(int index, T value);
};


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
inline void Node<T>::setValue(T value)
{
	this->value = value;
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


template <class T>
CList<T>::CList():head(nullptr),size(0)
{
}

template<class T>
inline CList<T>::CList(std::initializer_list<T> vInitList)
{
	for(const T *pi=vInitList.begin();pi!=vInitList.end();++pi)
		add(*pi);
}

template<class T>
int CList<T>::getSize() const
{
	return size;
}

template<class T>
T CList<T>::get(int index)
{
	if (index > size - 1)
		throw std::out_of_range("Current index: " + std::to_string(index) + "Current size: " + std::to_string(size));

	Node<T>* currentNode = head;

	for (int i = 0; i != index; i++)
		currentNode = currentNode->getNext();

	return (currentNode->getValue());
}

template<class T>
void CList<T>::add(T value)
{
	Node<T> *node = new Node<T>(value);
	if (head==nullptr) {
		head = node;
	}
	else
	{
		Node<T> *currentNode = head;
		while (currentNode->getNext()!=nullptr)
			currentNode = currentNode->getNext();

		currentNode->setNext(node);
		node->setPrevious(currentNode);
	}

	size++;
}



template<class T>
void CList<T>::set(int index, T value)
{
	if (index > size - 1)
		throw std::out_of_range("Current index: " + std::to_string(index) + "Current size: " + std::to_string(size));

	Node<T>* currentNode = head;

	for (int i = 0; i != index; i++)
		currentNode = currentNode->getNext();

	currentNode->setValue(value);
}
