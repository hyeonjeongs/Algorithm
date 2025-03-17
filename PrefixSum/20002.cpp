#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maxs = -1001;
int n;
vector<vector<int>> sums;
vector<vector<int>> arr;

void prefixSum(int x, int y) {

    int current = arr[y][x];
    if(x-1>=0) {
        current += sums[y][x-1];
    }
    if(y-1>=0) {
        current += sums[y-1][x];
    }
    if(x-1>=0 && y-1>=0) {
        current -= sums[y-1][x-1];
    }
    sums[y][x] = current;

}

void maxSum(int x, int y) {

    int mins = min(x, y)+ 1;

    maxs = max(maxs, arr[y][x]);

    for(int k=2; k<=mins; k++) {
        int current = sums[y][x];
        if(x-k>=0) {
            current -= sums[y][x-k];
        }
        if(y-k>=0) {
            current -= sums[y-k][x];
        }
        if(x-k >=0 && y-k >=0) {
            current += sums[y-k][x-k];
        }

        maxs = max(maxs, current);
    }
}

int main() {

    cin >> n;
    arr.assign(n, vector<int>(n,0));
    sums.assign(n, vector<int> (n, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            prefixSum(j, i);
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            maxSum(j, i);
        }
    }

    cout << maxs << '\n';

    return 0;
}