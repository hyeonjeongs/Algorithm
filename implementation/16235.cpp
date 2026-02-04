#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 11
using namespace std;

struct Tree {
    int x;
    int y;
    int age;

    bool operator<(const Tree& other) const {
        return age < other.age;
    }
};
int n, m, k;
vector<vector<int>> feed;
vector<vector<int>> a;

vector<Tree> deletes;
vector<int> arr[MAX][MAX];

int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void spring() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (arr[i][j].empty()) {
                continue;
            }
            sort(arr[i][j].begin(), arr[i][j].end());
            for (int u=0; u<arr[i][j].size();u++) {
                if (arr[i][j][u]<=feed[i][j]) {
                    feed[i][j]-=arr[i][j][u];
                    arr[i][j][u]++;
                } else {
                    deletes.push_back({j, i, arr[i][j][u]});
                    arr[i][j].erase(arr[i][j].begin()+u);
                    u--;
                }
            }
        }
    }

}
void summer() {
    for (int i=0; i<deletes.size(); i++) {
        int x = deletes[i].x;
        int y = deletes[i].y;
        int age = deletes[i].age/2;
        feed[y][x] += age;
    }

}
void fall() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int u=0; u<arr[i][j].size(); u++) {
                if (arr[i][j][u]>=5 && arr[i][j][u]%5==0) {
                    for (int l=0; l<8; l++) {
                        int nx = j + dx[l];
                        int ny = i + dy[l];
                        if (nx<1 || nx>n || ny<1 || ny>n) {
                            continue;
                        }
                        arr[ny][nx].push_back(1);
                    }
                }
            }
        }
    }

}
void winter() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            feed[i][j] += a[i][j];
        }
    }
}
int main() {


    cin >> n >> m >> k;
    feed.assign(n+1, vector<int>(n+1, 5));
    a.assign(n+1, vector<int>(n+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i=0; i<m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[x][y].push_back(z);
    }


    while (k--) {
        deletes.clear();

        spring();
        summer();
        fall();
        winter();
    }

    int result=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            result += arr[i][j].size();
        }
    }
    cout << result << '\n';
    return 0;

}