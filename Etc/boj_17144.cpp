#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector <int>> map(52, vector<int>(52, 0));

int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, 1, 0, -1};

void check_4(int r, int c, vector<vector <int>> &dmap) {
    int spread_count = 0;
    for (int i = 0; i < 4; i++) { 
        if (map[r + dr[i]][c + dc[i]] >= 0) {
            spread_count++;
            dmap[r + dr[i]][c + dc[i]] += floor(map[r][c]/5);
        }
    }
    map[r][c] -= floor(map[r][c]/5) * spread_count;
}

void spread(int r, int c) {
    vector<vector <int>> dmap(52, vector<int>(52, 0));

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            check_4(i, j, dmap);
        }
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            map[i][j] += dmap[i][j];
        }
    }    
}

void air_cleaner(int r, int c, int p)
{
    int i = p-1, j = 2, temp = 0;

    while (!(i == p-1 && j == 1)) {
        swap(temp, map[i][j]);

        if (i == p-1 && j != c)
            j += 1;
        else if (i != 1 && j == c)
            i -= 1;
        else if (i == 1 && j != 1)
            j -= 1;
        else
            i += 1;
    }
    
    ////////////////////////////////////////////////
    i = p, j = 2, temp = 0;

    while (!(i == p && j == 1)) {
        swap(temp, map[i][j]);

        if (i == p && j != c)
            j += 1;
        else if (i != r && j == c)
            i += 1;
        else if (i == r && j != 1)
            j -= 1;
        else
            i -= 1;
    }
}

int main() {
    int r, c, t, air_cleaner_position, result = 0;
    cin >> r >> c >> t;

    for (int i = 0; i <= r+1; i++) {
        for (int j = 0; j <= c+1; j++) {
            if (i == 0 || i == r+1 || j == 0 || j == c+1)
                map[i][j] = -2;
            else {
                cin >> map[i][j];
                if (map[i][j] == -1) {
                    air_cleaner_position = i;
                }
            }
        }
    }

    for (int k = 0; k < t; k++) {     
        spread(r, c);
        air_cleaner(r, c, air_cleaner_position);
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            //cout << map[i][j] << " ";
            if (map[i][j] > 0)
                result += map[i][j];
        }
        //cout << endl;
    }

    cout << result << endl;
    
    return 0;
}