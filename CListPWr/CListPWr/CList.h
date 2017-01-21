#pragma once
#include <stdexcept>
#include <string>

template <class T>
class Node
{
private:
	T value;
	Node* previous = nullptr;
	Node* next = nullptr;

public:
	Node(T value);
	Node(Node &pcOther);
	T getValue();
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
	Node<T>* head;
	int size=0;

public:
	//CList();
	//CList(std::initializer_list<T> vInitList);
	int getSize() const;
	T getNodeValue(int index);
	void add(T value);
};


