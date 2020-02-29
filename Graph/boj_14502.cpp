#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int map[8][8] = {0, };
int d_row[4] = {0, 1, 0, -1};
int d_col[4] = {-1, 0, 1, 0};
int combination_visited[65] = {0, }; // 8x8 + 1
int n, m, max_safety_zone = 0, wall_num = 0, space_num;
vector<pair<int, int> > v;
vector<int> combi;

void virus(int row, int col, int &virus_zone, vector<vector<int> > &visited)
{       
    virus_zone += 1;

    for (int i = 0; i < 4; i++)
    {
        int next_row = row + d_row[i];
        int next_col = col + d_col[i];
        
        if (next_row >= 0 && next_row < n  && next_col >= 0 && next_col < m && map[next_row][next_col] == 0 && !visited[next_row][next_col])
        {
            visited[next_row][next_col] = 1;
            virus(next_row, next_col, virus_zone, visited);
        }
    }
}

void combination(int idx, int cnt)
{
    if (cnt == 3)
    {   
        int virus_zone = 0, safety_zone;
        vector<vector<int> > visited(8, vector<int>(8,0)); 

        for (int i = 0; i < 3; i++)
            map[v[combi[i]].first][v[combi[i]].second] = 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (map[i][j] == 2 && !visited[i][j])
                    virus(i, j, virus_zone, visited);

        for (int i = 0; i < 3; i++)
            map[v[combi[i]].first][v[combi[i]].second] = 0;

        safety_zone = n * m - virus_zone - wall_num - 3;

        if (max_safety_zone < safety_zone)
            max_safety_zone = safety_zone;      

        return;      
    }
    
    for (int i = idx; i < space_num; i++)
    {
        if (!combination_visited[i])
        {
            combi.push_back(i);
            combination_visited[i] = 1;
            combination(i + 1, cnt + 1);
            combi.pop_back();
            combination_visited[i] = 0;
        }  
    }
}

int main()
{    

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0)
                v.push_back(make_pair(i,j));
            else if(map[i][j] == 1)
                wall_num += 1;
        }
    }      
    space_num = v.size();

    combination(0, 0);

    cout << max_safety_zone << endl;

    return 0;
}