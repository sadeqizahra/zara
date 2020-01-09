#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* prev;
	Node* next;
	
	Node(int aData, Node* aPrev, Node* aNext)
	: data(aData), prev(aPrev), next(aNext)
	{
	}
};

void pushBack(Node*& head, Node*& tail, int x);
void directPrint(Node* head);
void reversePrint(Node* tail);
void insert(Node*& head, Node* p, int x);
Node* erase(Node*& head, Node*& tail, Node* p);
void clear(Node*& head, Node*& tail);

int main()
{
		Node* head = nullptr;
		Node* tail = nullptr;
		
		int x;
		while (cin >> x)
		{
			pushBack(head, tail, x);
		}
		
		directPrint(head);
		reversePrint(tail);
		
		for (Node* p = head; p; p = p->next)
		{
			if (p->data % 2 == 0)
			{
				insert(head, p, 0);
			}
		}
		
		directPrint(head);
		reversePrint(tail);
		
		for (Node* p = head; p;)
		{
			if (p->data % 2 == 0)
			{
				p = erase(head, tail, p);
			}
			else {
				p = p->next;
			}
		}
		
		directPrint(head);
		reversePrint(tail);
		
		clear(head, tail);
}

void pushBack(Node*& head, Node*& tail, int x)
{
	if (head == nullptr)
	{
		head = tail = new Node(x, nullptr, nullptr);
	}
	else 
	{
		tail->next = new Node(x, tail, nullptr);
		tail = tail->next;
	}
}

void directPrint(Node* head)
{
	for (Node* p = head; p; p = p->next)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

void reversePrint(Node* tail)
{
	for (Node* p = tail; p; p = p->prev)
	{
		cout << p->data << " ";
	}
	cout << endl;
}

void insert(Node*& head, Node* p, int x)
{
	if (p != head)
	{
		Node* t = new Node(x, p->prev, p);
		t->next->prev = t;
		t->prev->next = t;
	}
	else {
		head = new Node(x, nullptr, head);
		head = head->prev;
	}
}

Node* erase(Node*& head, Node*& tail, Node* p)
{
	if (p == head && p == tail)
	{
		delete p;
		head = tail = nullptr;
		return nullptr;
	}
	else if (p == head)
	{
		head = p->next;
		head->prev = nullptr;
		delete p;
		return head;
	}
	else if (p == tail)
	{
		tail = p->prev;
		p->next = nullptr;
		delete p;
		return tail;
	}
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		Node* t = p->next;
		delete p;
		return t;
	}
}

void clear(Node*& head, Node*& tail)
{
	while (head)
	{
		cout << "Delete node: " << head->data << endl;

		Node* tmp = head->next;
		delete head;
		head = tmp;
	}
	
	head = tail = nullptr;
}