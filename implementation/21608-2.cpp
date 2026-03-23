# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
typedef pair<int, int> pi;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

vector<pi> maxs;
int max_cnt=0;
int n;
bool outOfBounds(int x, int y) {
    return x<0 || x>=n || y<0 || y>=n;
}
void finds(int y, int x, int current, vector<vector<int>> &arr, vector<vector<int>> &likes) {
    int cnt=0;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (outOfBounds(nx, ny) || arr[ny][nx] ==0) {
            continue;
        }
        int numbers = arr[ny][nx];
        for (int j=0; j<4; j++) {
            if (likes[current][j] == numbers) {
                cnt++;
                break;
            }
        }
    }
    if (cnt > max_cnt) {
        max_cnt = cnt;
        maxs =  {{y,x}};
    } else if (cnt == max_cnt) {
        maxs.push_back({y, x});
    }
}
void findEmpty(vector<vector<int>> &arr) {
    int emptys=0;
    vector<pi> emp;

    for (int i=0; i<maxs.size(); i++) {
        int cnt=0;
        int x = maxs[i].second;
        int y = maxs[i].first;
        for (int j=0; j<4; j++) { // 인접의 공백이 많은 것 찾기
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (outOfBounds(nx, ny)) {
                continue;
            }
            if (arr[ny][nx] ==0) {
                cnt++;
            }
        }
        if (cnt > emptys) {
            emp = {maxs[i]};
            emptys = cnt;
        } else if (cnt == emptys) {
            emp.push_back({y,x});
        }
    }
    maxs = emp;
}
int findScore(int y, int x, vector<vector<int>> &arr, vector<vector<int>> &likes) {
    int current = arr[y][x];
    int num = 0;

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (outOfBounds(nx, ny)) {
            continue;
        }
        int numbers = arr[ny][nx];
        for (int j=0; j<likes[current].size(); j++) {
            if (likes[current][j] == numbers) {
                num++;
                break;
            }
        }
    }
    int result = 0;
    if (num==1) {
        result =1;
    } else if (num==2) {
        result = 10;
    } else if (num==3) {
        result =100;
    } else if (num==4) {
        result = 1000;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<int>> likes(n*n+1);
    vector<int> order;
    for (int i=0 ; i< n*n; i++) {
        int num;
        cin >> num;
        order.push_back(num);
        for (int j=0; j<4; j++) {
            int input;
            cin >> input;
            likes[num].push_back(input);
        }
    }

    for (int i=0; i<n*n; i++) {
        int current = order[i];
        maxs.clear();
        max_cnt=0;

        for (int j=0; j<n; j++) {
            for (int m=0; m<n; m++) {
                if (arr[j][m]==0) {
                    finds(j,m, current, arr, likes);
                }
            }
        }
        findEmpty(arr);

        arr[maxs[0].first][maxs[0].second]=current;
    }
    int result = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            result += findScore(i, j, arr, likes);
        }
    }
    cout << result << '\n';
    return 0;
}