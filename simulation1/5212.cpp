#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1,1, 0,0};
int dy[] = {0,0,-1,1};


vector<vector<int>> findMap(vector<vector<int>> island, int r, int c) {
    vector<vector<int>> result = island;


    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            int cnt = 0;
            for(int k=0; k<4; k++) {
                if(island[i+dy[k]][j+dx[k]]==0) {
                    cnt++;
                }
            }
            if(cnt>=3) {
                result[i][j] = 0;
            }
        }
    }

    return result;
}

int main() {

    int r,c;
    cin>>r>>c;

    // 0이 바다, 1이 땅
    vector<vector<int>> island(r+2, vector<int>(c+2, 0));

    for(int i=1;i<=r;i++) {
        for(int j=1; j<=c; j++) {
            char ch;
            cin>> ch;
            if(ch == 'X') {
                island[i][j] = 1;
            }
        }
    }
    vector<vector<int>> result = findMap(island, r, c);


    int x_min=20, x_max=-1, y_min=20, y_max=-1;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            if(result[i][j] == 1) {
                if(x_min > j) {
                    x_min = j;
                }
                if(x_max <= j) {
                    x_max = j;
                }
                if(y_min >i ) {
                    y_min = i;
                }
                if(y_max <i) {
                    y_max = i;
                }
            }
        }
    }

    for(int i=y_min; i<=y_max; i++) {
        for(int j=x_min; j<=x_max; j++) {
            if(result[i][j]==1) {
                cout<<'X';
            } else{
                cout<<'.';
            }
        }
        cout<<'\n';
    }

    return 0;
}