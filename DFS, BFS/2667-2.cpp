# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;


int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int n;
int dfs (int y, int x, vector<vector<int>> &arr, int current) {
    int total = 1;
    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx<0 || nx>=n || ny<0 || ny>=n || arr[ny][nx]!=1) {
            continue;
        }
        arr[ny][nx] = current;
        total += dfs(ny, nx, arr, current);
    }
    return total;
}

int main() {

    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<int> nums;

    for (int i=0; i<n; i++) {
        string input;
        cin >> input;
        for (int j=0; j<n; j++) {
            arr[i][j] = input[j] - '0';
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (arr[i][j] == 1) {
                int current= nums.size()+2;
                arr[i][j] = nums.size()+2;
                int total = dfs(i, j, arr, current);
                nums.push_back(total);
            }

        }
    }
    sort(nums.begin(), nums.end());
    cout << nums.size() << '\n';
    for (int i=0; i<nums.size(); i++) {
        cout << nums[i] << '\n';
    }
    return 0;

}
