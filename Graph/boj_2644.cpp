#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> g[101];
queue<int> q;
int visited[101] = {0,};

int bfs(int start, int end)
{
    int cnt = 0;
    q.push(start);
    visited[start] = 1;
    
    while (!q.empty())
    {
        int itr = q.size();
        for (int k = 0; k < itr; k++)
        {
            int current_node = q.front();
            q.pop();

            if (current_node == end)
                return cnt;
           
            for (int i = 0; i < g[current_node].size(); i++)
            {
                int next_node = g[current_node][i];

                if (!visited[next_node])
                {                
                    q.push(next_node);
                    visited[next_node] = 1;
                }
            }
        }

        cnt += 1;
    }

    return -1;
}

int main()
{
    int n, start, end, t, result;
    cin >> n >> start >> end >> t;

    for (int k = 0; k < t; k++)
    {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    cout << bfs(start, end) << endl;

    return 0;
}