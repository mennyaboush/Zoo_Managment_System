#ifndef __ZOO_MyLinkedList_H
#define __ZOO_MyLinkedList_H

#include <iostream>
using namespace std;

template<class T>
class MyLinkedList
{
	class Node;

private:
	class Node
	{
		friend class MyLinkedList<T>;
	public:
		Node(const T& info);
		const T& getInfo() const;
		const Node* getNext() const;

	private:
		T info;
		Node* next;

	};

	Node* head;
	Node* tail;
	int physicalSize;

public:
	MyLinkedList();
	MyLinkedList(const MyLinkedList<T>& list) = delete;
	~MyLinkedList();

	void addToTail(const T& t);
	void removeFirstApperance(const T& t);
	bool contains(const T& item) const;
	int size() const;
	const MyLinkedList<T> operator=(const MyLinkedList<T>& list) = delete;
	template<class T>
	friend ostream& operator<<(ostream& os, const MyLinkedList<T>& list);


};

template<class T>
MyLinkedList<T>::MyLinkedList()
{
	head = nullptr;
	tail = head;
	physicalSize = 0;
}

template<class T>
MyLinkedList<T>::~MyLinkedList()
{
	Node* temp1 = head;
	Node* temp2;
	if (head)
		temp2 = head->next;
	else
		return;
	while (temp1 != nullptr)
	{
		delete temp1;
		temp1 = temp2;
		if (temp1)
			temp2 = temp2->next;
	}
}

template<class T>
void MyLinkedList<T>::addToTail(const T& info)
{
	if (head == nullptr)
	{
		head = new Node(info);
		tail = head;
	}
	else
	{
		tail->next = new Node(info);
		tail = tail->next;
	}
	physicalSize++;
}

template<class T>
void MyLinkedList<T>::removeFirstApperance(const T& info)
{
	Node* ptr1 = head;
	Node* ptr2 = head->next;

	if (head->info == info)
	{
		ptr1 = head;
		head = head->next;
		delete ptr1;
		physicalSize--;
		return;
	}

	while (ptr2 != nullptr)
	{
		if (ptr2->info == info)
		{
			if (ptr2 == tail)
			{
				tail = ptr1;
			}
			ptr1->next = ptr2->next;
			physicalSize--;
			delete ptr2;
			return;
		}
	}
}
template<class T>
bool MyLinkedList<T>::contains(const T& item) const
{
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->info == item)
		{
			return true;
		}
		temp = temp->next;
	}
	return false;

}

template<class T>
int MyLinkedList<T>::size() const
{ 
	return physicalSize;
}



template<class T>
MyLinkedList<T>::Node::Node(const T& t) : info(t)
{
	this->next = nullptr;
}

template<class T>
const T& MyLinkedList<T>::Node::getInfo() const
{
	return MyLinkedList<T>::Node::info;
}

template<class T>
const typename MyLinkedList<T>::Node* MyLinkedList<T>::Node::getNext() const
{
	return MyLinkedList<T>::Node::next;
}

template<class T>
ostream& operator<<(ostream& os, const MyLinkedList<T>& list)
{
	const typename MyLinkedList<T>::Node* temp = list.head;
	while (temp != nullptr)
	{
		os << *temp->getInfo() << endl;
		temp = temp->getNext();
		os << endl;
	}
	return os;
}
#endif
