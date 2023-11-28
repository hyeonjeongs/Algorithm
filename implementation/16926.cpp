#include <iostream>
#include <vector>

using namespace std;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void turnArray(vector <vector<int>> &arr, int n, int m, int r, int depth) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < depth; j++) {
            int startValue = arr[j][j];
            int r = j, c = j;
            int way = 0;

            while (way < 4) {
                int new_r = r + dr[way];
                int new_c = c + dc[way];

                if(new_r ==j && new_c == j) {
                    break;
                }
                if (new_r >= j && new_r < n - j && new_c >= j && new_c < m - j) {
                    arr[r][c] = arr[new_r][new_c];
                    r = new_r;
                    c = new_c;
                } else {
                    way++;
                }
            }

            arr[j + 1][j] = startValue;
        }
    }

}

int main() {
    int n, m, r;
    int depth;
    cin >> n >> m >> r;
    vector <vector<int>> arr(n+1, vector<int>(m+1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    depth = min(n, m) / 2;

    turnArray(arr, n, m, r, depth);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }

    return 0;
}