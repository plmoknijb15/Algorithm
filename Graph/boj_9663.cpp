// N-Queen

#include <iostream>
#include <vector>

using namespace std;

int chessboard[16][16] = {0, };
int n, my_count = 0;
int k = 0;
void DFS(int row)
{	
	int check_row, check_col;

	if (row > n)
	{
		my_count += 1;
		return;
	}
	
	for (int col = 1; col <= n; col++)
	{
		int flag = 0, test_row = row, test_col = col;

		while (test_row > 1)
		{
			test_row -= 1;
			if (chessboard[test_row][test_col] == 1)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			test_row = row, test_col = col;
			while (test_row > 1 && test_col > 1)
			{
				test_row -= 1;
				test_col -= 1;
				if (chessboard[test_row][test_col] == 1)
				{
					flag = 1;
					break;
				}
			}
		}
		
		if (flag == 0)
		{
			test_row = row, test_col = col;
			while (test_row > 1 && test_col < n)
			{
				test_row -= 1;
				test_col += 1;
				if (chessboard[test_row][test_col] == 1)
				{
					flag = 1;
					break;
				}
			}
		}

		if (flag == 0)
		{
			chessboard[row][col] = 1;
			DFS(row + 1);
			chessboard[row][col] = 0;
		}
	}
}

int main()
{
	cin >> n;

	DFS(1);
	cout << my_count << endl;
	
	return 0;
}