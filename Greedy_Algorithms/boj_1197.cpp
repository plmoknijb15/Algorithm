#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<pair<int, int>, int>> g;
int parent[10001] = {0,};
long long int result = 0;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.second < b.second)
        return true;
    else
        return false;
}

int Find(int node)
{
    if (node == parent[node])
        return node;
    
    return parent[node] = Find(parent[node]);
}

void Union(int node1, int node2, int weight)
{
    int p1 = Find(node1);
    int p2 = Find(node2);

    if (p1 == p2)
        return;

    if (p1 < p2)
        parent[p2] = p1;
    else
        parent[p1] = p2;

    result += weight;
}

int main() 
{
    int v, e;
    cin >> v >> e;

    for (int i = 1; i <= v; i++)
        parent[i] = i;

    for (int i = 0; i < e; i++)
    {
        int node1, node2, weight;
        scanf("%d %d %d", &node1, &node2, &weight);    

        g.push_back(make_pair(make_pair(node1, node2), weight));
    }
    
    sort(g.begin(), g.end(), compare);

    for (int i = 0; i < e; i++)
        Union(g[i].first.first, g[i].first.second, g[i].second);
    
    cout << result << endl;
    
    return 0;
}