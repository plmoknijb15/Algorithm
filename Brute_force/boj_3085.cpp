// 사탕 게임

#include <iostream>

using namespace std;

int n, max_count = 0;
char map[51][51] = {0, };

void check_up(int i, int j, int &count) {
   if (i-1 != 0 && map[i - 1][j] == map[i][j]) {
       count += 1;
       check_up(i-1, j, count);
   }

}

void check_down(int i, int j, int &count) {
    if (i != n && map[i + 1][j] == map[i][j]) {
       count += 1;
       check_down(i+1, j, count);
   }

}

void check_left(int i, int j, int &count) {
    if (j - 1 != 0 && map[i][j - 1] == map[i][j]) {
       count += 1;
       check_left(i, j-1, count);
   }

}

void check_right(int i, int j, int &count) {
    if (j != n && map[i][j+1] == map[i][j]) {
       count += 1;
       check_right(i, j+1, count);
   }

}

int main() {
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> map[i][j];

    
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) {
            int count = 1;

            check_up(i, j, count);
            check_down(i, j, count);

            if (max_count < count)
                max_count = count;
                
            count = 1;
            check_left(i, j, count);
            check_right(i, j, count);
            
            if (max_count < count)
                max_count = count;
        }
    }

        
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 아래랑 교환
            if (i < n && map[i][j] != map[i+1][j])
            {
                int count = 1;
                swap(map[i][j], map[i+1][j]);
 
                check_up(i, j, count);
                check_down(i, j, count);

                if (max_count < count)
                    max_count = count;

                count = 1;
                check_left(i, j, count);
                check_right(i, j, count);
            
                if (max_count < count)
                    max_count = count;

                //////////////////////////////////////
                count = 1;
                check_up(i + 1, j, count);
                check_down(i + 1, j, count);
            
                if (max_count < count)
                    max_count = count;

                count = 1;
                check_left(i+1, j, count);
                check_right(i+1, j, count);
            
                if (max_count < count)
                    max_count = count;

                
                swap(map[i][j], map[i+1][j]);
            }
    

            // 오른쪽이랑 교환
            if (j < n && map[i][j] != map[i][j+1])
            {
                int count = 1;
                swap(map[i][j], map[i][j+1]);
 
                check_up(i, j, count);
                check_down(i, j, count);

                if (max_count < count)
                    max_count = count;

                count = 1;
                check_left(i, j, count);
                check_right(i, j, count);
            
                if (max_count < count)
                    max_count = count;

                /////////////////////////
                count = 1;
                check_up(i, j+1, count);
                check_down(i, j+1, count);
            
                if (max_count < count)
                    max_count = count;

                count = 1;
                check_left(i, j+1, count);
                check_right(i, j+1, count);
            
                if (max_count < count)
                    max_count = count;
            
                swap(map[i][j], map[i][j+1]);
            }
        }
    }

    cout << max_count << endl;

    return 0;
}       