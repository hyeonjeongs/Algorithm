#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int dx[]= {0,-1,-1,0,1,1,1,0,-1};
int dy[] = {0,0,-1,-1,-1,0,1,1,1};

int main() {
    int n, m;
    vector<vector<int>> basket;
    vector<pi> dist;

    cin >> n >> m;
    basket.assign(n, vector<int>(n, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> basket[i][j];
        }
        
    }
    for(int i=0; i<m ; i++) {
        int a, b;
        cin >> a >> b;
        dist.push_back({a, b}); // dir, dist
    }

    vector<pi> cloud = {{n-2,0},{n-2,1},{n-1,0},{n-1,1}}; // (y,x)


    for(int i=0; i<m; i++) {
        vector<vector<bool>> isCloud(n, vector<bool>(n, false));
        // 구름 이동
        for(int j=0; j<cloud.size(); j++) {
            cloud[j].first = (cloud[j].first + dy[dist[i].first] * dist[i].second + n*dist[i].second)%n; // y
            cloud[j].second = (cloud[j].second + dx[dist[i].first] * dist[i].second + n*dist[i].second)%n; // x
            isCloud[cloud[j].first][cloud[j].second] = true;
        }

        // 구름 있는 곳에 1증가, 대각선 만큼 증가
        for(int j=0; j<cloud.size(); j++) {
            int cx = cloud[j].second;
            int cy = cloud[j].first;
            basket[cy][cx]++; // y
        }
        for(int j=0; j<cloud.size(); j++) {
            int cx = cloud[j].second;
            int cy = cloud[j].first;

            for(int k=2; k<=8; k+=2) {
                int nx = dx[k] + cx;
                int ny = dy[k] + cy;
                if(nx<0 || ny<0 || nx>=n || ny>=n || basket[ny][nx]<=0) {
                    continue;
                }
                basket[cy][cx]++;
            }
        }

        // 물의 양 2 이상인 칸에 구름 생성 -> 물의 양 2만큼 줄어든다
        vector<pi> new_cloud;
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(isCloud[j][k] || basket[j][k]<2) {
                    continue;
                }
                new_cloud.push_back({j, k});
                basket[j][k]-=2;
            }
        }
        cloud = new_cloud;
    }

    int result = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            result += basket[i][j];
        }
    }

    cout << result << '\n';

    return 0;
}