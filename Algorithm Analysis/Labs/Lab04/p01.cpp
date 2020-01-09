#include <iostream>

using namespace std;

void readAndReverse()
{
	int x;
	if (cin >> x)
	{
		readAndReverse(); #Recursion: calling a function inside itself.
		cout << " " << x;
	}
}

int main()
{
	readAndReverse();
}