// 1,2,3 더하기

#include <iostream>

using namespace std;

int func(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;

	return func(n - 3) + func(n - 2) + func(n - 1);
}

int main()
{
	int t, n;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << func(n) << endl;
	}
	
	return 0;
}