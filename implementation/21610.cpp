#include <iostream>
#include <vector>

using namespace std;
typedef pair<int ,int> pi;
int dx[] = {0, -1,-1,0,1,1,1,0,-1};
int dy[] = {0, 0,-1,-1,-1,0,1,1,1};
int n, m;
vector<vector<int>> basket;
vector<vector<bool>> visited;
vector<pi> cloud;

bool outOfBound(int x, int y) {
    return (x<1 || x>n || y<1 || y>n);
}

void moveDirection(int dir, int s) {

    int ddx = dx[dir];
    int ddy = dy[dir];

    // 이동
    for(int i=0; i<cloud.size(); i++) {
        int nx= cloud[i].second;
        int ny= cloud[i].first;
        if(ddx < 0) {
            nx = ((nx-1) + ddx*s + n*s)%n +1;
        }else {
            nx = ((nx-1) + ddx*s)%n +1;
        }
        if(ddy < 0) {
            ny = ((ny-1) + ddy*s + n*s)%n +1;
        }else {
            ny = ((ny-1) + ddy*s)%n +1;
        }
        cloud[i] = {ny, nx};
        visited[ny][nx] = true;
        basket[ny][nx] +=1;
    }

    for(int i=0; i<cloud.size(); i++) {
        int cnt = 0;
        int cy= cloud[i].first;
        int cx = cloud[i].second;
        for(int j=2; j<=8; j+=2) {
            int ny = cy + dy[j];
            int nx = cx + dx[j];
            if(outOfBound(nx, ny)) {
                continue;
            }
            if(basket[ny][nx]>0) {
                cnt++;
            }
        }
        basket[cy][cx] += cnt;
    }

}
void makeCloud() {
    vector<pi> current;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(basket[i][j]>=2 && !visited[i][j]) {
                current.push_back({i, j});
                basket[i][j] -=2;
            }
        }
    }
    cloud = current;
}

int resultSum() {
    int sum= 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            sum += basket[i][j];
        }
    }
    return sum;
}
int main() {

    cin >> n>> m;
    cloud ={{n,1}, {n,2}, {n-1,1}, {n-1,2}};  // (y,x)
    basket.assign(n+1, vector<int>(n+1, 0));


    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> basket[i][j];
        }
    }

    for(int i=0; i<m; i++) {
        int d, s;
        cin >> d >> s;
        visited.assign(n+1, vector<bool>(n+1, false));
        moveDirection(d, s);
        makeCloud();
    }

    cout <<resultSum();

    return 0;
}