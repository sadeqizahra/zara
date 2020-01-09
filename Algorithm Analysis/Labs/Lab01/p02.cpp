#include <iostream>
#include <list>

using namespace std;

void printInDirectOrder(const list<int>& lst)
{
	for (auto e: lst)
	{
		cout << e << " ";
	}
	cout << endl;
}

void printInReverseOrder(const list<int>& lst)
{
	for (auto it = lst.rbegin(); it != lst.rend(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	list<int> lst;
	cout << sizeof(lst) << endl;
	
	int x;
	while (cin >> x)
	{
		lst.push_back(x);
	}
	
	printInDirectOrder(lst);
	printInReverseOrder(lst);
	
	for (auto it = lst.begin(); it != lst.end();)
	{
		if (*it % 2 == 0)
		{
			it = lst.insert(it, 0);
			++it;
		}
		++it;
	}
		
	printInDirectOrder(lst);
	printInReverseOrder(lst);
	
	
	return 0;
}