#include <iostream>
#include"SimpleLinkedList.h"
using namespace std;
using std::string;


SimpleLinkedList::SimpleLinkedList()
{
	head = cursor = prev = nullptr;
}

SimpleLinkedList::~SimpleLinkedList()
{
	MakeListEmpty();
}

bool SimpleLinkedList::IsEmpty() const
{
	return head == nullptr;
}

bool SimpleLinkedList::IsCursorEmpty() const
{
	return cursor == nullptr;
}

void SimpleLinkedList::ToFirst()
{
	cursor = head;
	prev = nullptr;
}

bool SimpleLinkedList::IsAtFirst() const
{
	return cursor == head;
}

void SimpleLinkedList::Advance()
{
	if (IsEmpty() || IsCursorEmpty())return;
	prev = cursor;
	cursor = cursor->next;
}

void SimpleLinkedList::ToEnd()
{
	ToFirst();
	while ( cursor->next != NULL) Advance();
}

bool SimpleLinkedList::IsAtEnd() const
{
	return (IsEmpty() || (!IsCursorEmpty() && cursor->next == NULL));
}

int SimpleLinkedList::Size() const
{
	NodePointer p = head;
	int count =0;
	while (p != NULL)
	{
		count++; 	
		p = p->next;
	}
	return count;
}

void SimpleLinkedList::UpdateData(const char &d)
{
	cursor->data = d;
}

void SimpleLinkedList::RetrieveData(char &d, int &k) const
{
	d = cursor->data;
	k = cursor->key;
}

void SimpleLinkedList::RetrieveKey(int &k) const
{
	k = cursor->key;
}

void SimpleLinkedList::InsertFirst(const int &k, const char &d )
{
	NodePointer p;
	p = new Node;
	p->key = k; 
	p->data = d;
	p->next = head;
	head = cursor = p;
	prev = nullptr;
}

void SimpleLinkedList::InsertAfter(const int &k, const char &d )
{
	NodePointer p;
	p = new Node;
	p->key = k;
	p->data = d;
	p->next = cursor->next;
 	cursor->next = p;
	prev = cursor;
	cursor = cursor->next;
}

void SimpleLinkedList::InsertBefore(const int &k, const char &d )
{
	NodePointer pnew;
	pnew = new Node;
	pnew->key = k; pnew->data = d;
	pnew->next = cursor;
    prev->next = pnew;
	cursor = pnew;
}

void SimpleLinkedList::InsertEnd(const int &k, const char &d )
{
	if (IsEmpty()) InsertFirst(k,d);
	else {ToEnd(); InsertAfter(k,d); }
}

void SimpleLinkedList::DeleteNode()
{
	NodePointer p;
	if (IsEmpty()) return;
	if (IsAtFirst())
	{
		p = cursor;
		head = cursor = cursor->next;
		delete p;
		return;
	};

	p = cursor;
	cursor = cursor->next;
	prev->next = cursor;
	delete p;
}

void SimpleLinkedList::DeleteFirst()
{
	if(!IsEmpty()) 
	{
		ToFirst();
		DeleteNode();
	}
}

void SimpleLinkedList::DeleteEnd()
{
	if(!IsEmpty()) 
	{
		ToEnd();
		DeleteNode();
	}
}

void SimpleLinkedList::MakeListEmpty()
{
	if (IsEmpty()) return;
    ToFirst();
	while (!IsEmpty())
	{
		 DeleteNode();
	}
}

bool SimpleLinkedList::Search(const int &k)
{
  	ToFirst();
	while (!IsCursorEmpty() && k != cursor->key)
	{
		Advance();
	}
	return !IsCursorEmpty();
}

void SimpleLinkedList::OrderInsert(const int& k, const char& d)
{
	ToFirst();
	while (!IsCursorEmpty() && (k > cursor->key))
		Advance();
	if (IsAtFirst())  InsertFirst(k, d);
	else InsertBefore(k, d);
}

void SimpleLinkedList::Traverse()
{
	ToFirst();
	cout << "=========================" << endl;
	while (!IsCursorEmpty())
	{
		cout << cursor->data << " - "<<cursor->key << endl;
		Advance();
	}
	cout << "=========================" << endl << endl;
}


