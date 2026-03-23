#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int dx[] = {0, -1,-1,0,1,1,1,0,-1};
int dy[] = {0, 0,-1,-1,-1,0,1,1,1};
vector<vector<int>> basket;
vector<vector<int>> cloud;
vector<pi> location;
int n, m;

void moveCloud(int d, int s) {
    for (int i=0; i<location.size(); i++) {
        int nx = (location[i].first + dx[d]*s%n + n)%n;
        int ny = (location[i].second + dy[d]*s%n + n)%n;
        location[i] = {nx, ny};
        cloud[ny][nx] = 1;
    }
}

void rainCloud() {
    for (int i=0; i<location.size(); i++) {
        int x = location[i].first;
        int y = location[i].second;
        basket[y][x]++;
    }
    for (int i=0; i<location.size(); i++) {
        int x = location[i].first;
        int y = location[i].second;
        int cnt=0;
        for (int j=2; j<9; j+=2) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx<0 || nx>=n || ny<0 || ny>=n) {
                continue;
            }
            if (basket[ny][nx]>0) {
                cnt++;
            }
        }
        basket[y][x] += cnt;
    }
}
void disappear() {
    vector<pi> news;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (basket[i][j]>=2 && cloud[i][j]==0) {
                news.push_back({j, i});
                basket[i][j] -=2;
            }
        }
    }
    cloud.assign(n, vector<int>(n, false));
    location = news;
}
int main() {
    cin >> n >> m;
    basket.assign(n, vector<int>(n, 0));
    cloud.assign(n, vector<int>(n, 0));

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> basket[i][j];
        }
    }
    for (int i=n-2; i<n; i++) {
        for (int j=0; j<2; j++) {
            location.push_back({j, i});
        }
    }
    for (int i=0; i<m; i++) {
        int d, s;
        cin >> d >> s;
        moveCloud(d, s);
        rainCloud();
        disappear();
    }
    int result = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            result += basket[i][j];
        }
    }
    cout << result << '\n';

    return 0;
}