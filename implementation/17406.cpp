#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int mins= 1e8;
vector<vector<int>> spinArr(vector<vector<int>> arr,vector<int> spin) {
    int sx = spin[1] - spin[2];
    int sy = spin[0] - spin[2];
    int ex = spin[1] + spin[2];
    int ey = spin[0] + spin[2];
    int num = ex - sx + 1; // 반복순서
    int depth = num/2;

    vector<vector<int>> copy_arr = arr;

    for(int i=0; i<depth; i++) {
        int cx = sx + i;
        int cy = sy + i;

        for(int j=0; j<4; j++) {
            int count = 1;
            while(count < num) {
                arr[cy+dy[j]][cx+dx[j]] = copy_arr[cy][cx];
                cx = cx + dx[j];
                cy = cy + dy[j];
                count++;
            }
        }
        num -= 2;
    }


    return arr;

}

void calculateArr(vector<vector<int>> arr) {

    for(int i=1; i<arr.size(); i++) {
        int current = 0;
        for(int j=1; j<arr[i].size(); j++) {
            current += arr[i][j];
        }
        mins = min(mins, current);
    }
}

int main()
{
    int n,m,k;
    cin >> n>> m>>k;
    vector<vector<int>> arr(n+1, vector<int>(m+1, 0));
    vector<vector<int>> spin(k,vector<int>(3,0));
    vector<int> order(k,0); //예비
    vector<vector<int>> orders;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin>> arr[i][j];
        }
    }
    for(int i=0; i<k; i++) {
        cin>> spin[i][0] >> spin[i][1] >> spin[i][2];
        order[i] = i;
    }

    do {
        orders.push_back(order);
    }while(next_permutation(order.begin(), order.end()));

    vector<vector<int>> copy_arr;

    for(int i=0; i<orders.size(); i++) {
        vector<vector<int>> copy_arr = arr;
        for(int j=0; j<orders[i].size(); j++) {
            copy_arr = spinArr(copy_arr, spin[orders[i][j]]);
        }
        calculateArr(copy_arr);
    }

    cout << mins << '\n';
    return 0;
}