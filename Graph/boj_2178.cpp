#include <iostream>
#include <queue>

using namespace std;

int map[102][102] = { 0, };

int d_col[4] = { 0, 1, 0, -1 };
int d_row[4] = { -1, 0, 1, 0 };
int n, m;

class Node
{
public:
	int row, col, count;
	Node(int _row, int _col, int _count) : row(_row), col(_col), count(_count)
	{}
};

int bfs()
{
	queue<Node> q;

	q.push(Node(1, 1, 1));
	map[1][1] = 0;

	while (!q.empty())
	{
		Node current_node = q.front();
		q.pop();

		if (current_node.row == n && current_node.col == m)
			return current_node.count;
		
		for (int i = 0; i < 4; i++)
		{
			if (map[current_node.row + d_row[i]][current_node.col + d_col[i]])
			{
				q.push(Node(current_node.row + d_row[i], current_node.col + d_col[i], current_node.count + 1));
				map[current_node.row + d_row[i]][current_node.col + d_col[i]] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d",&n, &m);

	for (int row = 1; row <= n; row++)
		for (int col = 1; col <= m; col++)
			scanf("%1d", &map[row][col]);

	printf("%d", bfs());

	return 0;
}