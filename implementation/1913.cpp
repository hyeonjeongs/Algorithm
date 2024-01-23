#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main() {
    int n, k;
    int x=0, y=-1;
    int result[2] = {0,0};
    cin >> n >> k;

    vector<vector<int>> spin(n+2, vector<int>(n+2,0));
    int num = n*n;

    for (int i = 0; i <= n + 1; ++i) {
        spin[0][i] = spin[n + 1][i] = spin[i][0] = spin[i][n + 1] = -1;
    }

    x=1; y=0;
    while(num>=1) {
        for(int i=0 ;i<4; i++) {
            if(num<1) {
                break;
            }

            while(true) {
                if(num<1) {
                    break;
                }
                x += dx[i];
                y += dy[i];

                if(spin[y][x] !=0) {

                    x -= dx[i];
                    y -= dy[i];
                    break;
                }
                if(num == k){
                    result[0] = y; result[1] = x;
                }

                spin[y][x] = num--;

            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<= n; j++) {
            cout<<spin[i][j] << ' ';
        }
        cout<< '\n';
    }
    cout<< result[0] << ' ' << result[1] <<'\n';

    return 0;
}