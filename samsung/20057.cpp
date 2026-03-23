# include <iostream>
# include <vector>

using namespace std;
int n;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1}; // 왼 아 오 위

double percents[] = {0,0.05,0.1,0.1,0.07,0.07,0.02,0.02,0.01,0.01};
int ddx[4][10] = {
    {-1,-2,-1,-1,0,0,0,0,1,1},{0,0,-1,1,1,-1,2,-2,1,-1}, {1,2,1,1,0,0,0,0,-1,-1}, {0,0,-1,1,1,-1,2,-2,1,-1}
};
int ddy[4][10] = {
    {0,0,1,-1,1,-1,2,-2,1,-1},{1,2,1,1,0,0,0,0,-1,-1}, {0,0,1,-1,1,-1,2,-2,1,-1},{-1,-2,-1,-1,0,0,0,0,1,1}
};
bool outOfRange(int x, int y) {
    return x<0 || x>=n || y<0 || y>=n;
}
int result = 0;
void spins(vector<vector<int>> sand) {
    int x = n/2, y = n/2;
    int cnt =0;
    int index =0;
    int num = 1;

    while (1) {

        if (x==0 && y==0) {
            break;
        }
        for (int j=0; j<num; j++) {

            x += dx[index];
            y += dy[index];
            if (x==-1) {
                x=0;
            }

            int total = sand[y][x];

            int remain= total;
            for (int i=1; i<10; i++) {
                int nx = x + ddx[index][i];
                int ny= y + ddy[index][i];

                int nums = total * percents[i];
                remain -= nums;
                if (outOfRange(nx, ny)) {

                    result += nums;

                } else {
                    sand[ny][nx] += nums;
                }

            }
            int nx = x + ddx[index][0];
            int ny = y + ddy[index][0];
            if (outOfRange(nx, ny)) {
                result += remain;
            } else {
                sand[ny][nx] += remain;
            }
            sand[y][x] = 0;
        }
        index = (index+1)%4;
        cnt++;

        if (cnt==2) {
            cnt = 0;
            num++;
        }

    }
}

int main() {

    cin >> n;
    vector<vector<int>> sand(n, vector<int>(n, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> sand[i][j];
        }
    }
    spins(sand);

    cout << result << '\n';
    return 0;
}