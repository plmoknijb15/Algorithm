#include <iostream>

using namespace std;

int map[50][50];
int count;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    while (true) {
        if (map[r][c] == 0) {
            count++;
            map[r][c] = 2;
        }   

        bool go_back = false;
        for (int i = 0; i <= 3; i++) {
            int check_x = r + dx[(d+3-i) % 4];
            int check_y = c + dy[(d+3-i) % 4];
            
            if (map[check_x][check_y] == 0) {
                r = check_x;
                c = check_y;
                d = (d+3-i) % 4;
                break;
            }

            if (i == 3)
                go_back = true;
        }
        
        if (go_back) {
            int check_x = r + dx[(d+2) % 4];
            int check_y = c + dy[(d+2) % 4];

            if (map[check_x][check_y] != 1) {
                r = check_x;
                c = check_y;
            }
            else
                break;
        }
    }
    
    cout << count << endl;

    return 0;
}