#include <iostream>
#include <stdexcept>

using namespace std;

int gcd(int a, int b)
{
	if (a == 0 and b == 0) 
		throw runtime_exception("gcd(a, b): a = 0 and b = 0 is undefined");
	return gcd_AUX(abs(a), abs(b));
}
int gcd_AUX(int a, int b)
{
	
	if (a == 0)
		return b;
	
	if (b == 0)
		return a;
	
	return gcd_AUX(b, a % b);
}

int main()
{
	int a;
	int b;
	
	while (cin >> a >> b)
	{
		cout << "gcd(" << a << ", " << b << ") = " << gcd_AUX(a, b) << endl;
		
	}
}