// File:ListAppl.cpp
// Applies List Class: Ordered linked list

#include <iostream>
#include <string>
#include "SimpleLinkedList.h"
#include"stdio.h"
using namespace std;
using std::string;

int main()
{
	SimpleLinkedList L;
	L.InsertFirst(0, '0');
	L.InsertAfter(1, 'A');
	L.InsertAfter(4,'D');
	L.InsertBefore(2, 'B');
	L.OrderInsert(3, 'C');

	cout << "is 4 exists ?: " << (L.Search(4) ? "Yes" : "No") << endl;
	cout << "size:" << L.Size() << endl;
	L.Traverse();
	
	L.DeleteEnd();
	L.DeleteFirst();

	cout << "is 4 exists ?:" << (L.Search(4) ? "Yes" : "No") << endl;
	cout << "size:" << L.Size() << endl;
	L.Traverse();

	L.MakeListEmpty();
	cout << "size:" << L.Size() << endl;
	L.Traverse();

	return 0;
}
