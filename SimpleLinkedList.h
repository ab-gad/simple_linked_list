class SimpleLinkedList
{
	public:
		SimpleLinkedList();
		~SimpleLinkedList();

		bool IsEmpty() const;
		bool IsCursorEmpty() const;
		bool IsAtFirst() const;
		bool IsAtEnd() const;
		void Advance();
		void ToFirst();
		void ToEnd();
		int  Size() const;
		void UpdateData(const char & );
		void RetrieveData(char &, int &) const;
		void RetrieveKey(int &) const;
		void InsertFirst(const int &, const char & );
		void InsertAfter(const int &, const char & );
		void InsertBefore(const int &, const char& );
		void InsertEnd(const int &, const char & );
		void DeleteNode();
		void DeleteFirst();
		void DeleteEnd();
		void MakeListEmpty();
		bool Search(const int & );
		void OrderInsert(const int &, const char&);
		void Traverse();

	private:
	   class Node
	   {
			public:
				int key; 		
				char data;		
				Node *next = nullptr;
		};

		typedef Node * NodePointer;
		NodePointer head, cursor, prev;
};
