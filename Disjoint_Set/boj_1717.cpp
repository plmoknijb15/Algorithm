#include <iostream>

using namespace std;

int parent[1000001] = {0,};

int Find(int node1)
{
    if (node1 == parent[node1])
        return node1;

    return parent[node1] = Find(parent[node1]);
}

void Union(int node1, int node2)
{
    int p1 = Find(node1);
    int p2 = Find(node2);

    if (p1 < p2)
        parent[p2] = p1;
    else
        parent[p1] = p2;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int op, node1, node2;
        scanf("%d %d %d", &op, &node1, &node2);

        if (op == 0)
            Union(node1, node2);
        else if (op == 1)
        {   
            int p1 = Find(node1);
            int p2 = Find(node2);

            if (p1 == p2)
                printf("YES\n");
            else
                printf("NO\n");
        }        
    }

    return 0;
}