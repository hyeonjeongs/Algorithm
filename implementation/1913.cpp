#include <iostream>
#include <vector>

using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int main() {
    int n, k;
    int x=0, y=-1;
    int result[] = {};
    cin >> n >> k;

    vector<vector<int>> spin(n+2, vector<int>(n+2,0));
    int num = n*n;

    for(int i=0; i<4; i++) {
        while(true) {
            x += dx[i];
            y += dy[i];
            if(x<0 || x>n+1 || y<0 || y>n+1) {
                x -= dx[i];
                y -= dy[i];
                break;
            }
            spin[y][x] = -1;
        }

    }

    x=1; y=0;
    while(num>3) {
        for(int i=0 ;i<4; i++) {
            if(num<3) {
                break;
            }

            while(true) {
                if(num<3) {
                    break;
                }
                x += dx[i];
                y += dy[i];
                if(num <=5 ) {
                    cout<< x<< ' ' << y << " -> " << num <<endl;
                    cout<< "dx : "<< dx[i] << " dy : " << dy[i] <<endl;
                }
                if(spin[y][x] !=0) {
                    cout<< x << ' '<< y << " 입니다" << endl;
                    x -= dx[i];
                    y -= dy[i];
                    break;
                }
                if(num == k){
                    result[0] = y; result[1] = x;
                }
                cout<<num << " !!"<<endl;
                spin[y][x] = num--;
                cout<<spin[y][x] << " !??"<<endl;
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