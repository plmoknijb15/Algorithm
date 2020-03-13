#include <iostream>

using namespace std;

char arr[50][50] = {0, };

int check_8x8(int n, int m)
{
	int cnt = 0, flag = 0;

	for (int i = n; i < n+8; i++)
	{
		for (int j = m; j < m+8; j++)
		{
			if (arr[i][j] == 'W' && flag != 1)
				cnt += 1;
			else if (arr[i][j] == 'B' && flag != -1)
				cnt += 1;

			if (i == n && j == m)
				(arr[i][j] == 'W') ? flag = 1 : flag = -1;
			else
				flag *= -1;
		}

		flag *= -1;
	}

	return (64-cnt < 32) ? 64-cnt : cnt;
}


int main()
{
	int n, m, cnt, min = 999;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		getchar();
		for (int j = 0; j < m; j++)
			scanf("%1c", &arr[i][j]);
	}

	for (int i = 0; i < n-7; i++)
	{
		for (int j = 0; j < m-7; j++)
		{
			cnt = check_8x8(i, j);
			if (cnt < min)
				min = cnt;
		}
	}

    cout << min << endl;

	return 0;
}
