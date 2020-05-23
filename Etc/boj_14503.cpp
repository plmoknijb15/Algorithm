#include <iostream>

using namespace std;

int map[51][51];

int main()
{
    int n, m, r, c, d;
    cin >> n >> m >> r >> c >> d;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; i <= m; j++) {
            cin >> map[i][j];
            cout << map[i][j] << " "; 
        }
        cout << endl;
    }
        
    return 0;
}