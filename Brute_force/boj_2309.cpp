#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int arr[9];
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				arr[i] = 999;
				arr[j] = 999;

				sort(arr, arr + 9);
				for (int k = 0; k < 7; k++)
					cout << arr[k] << endl;
				
				exit(0);
			}
		}
	}

	return 0;
}
