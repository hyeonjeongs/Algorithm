#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<vector<int>> arr;
vector<bool> result;
int diffs = 10000;
void calcDiff(int cnt) {

    int a_sum=0;
    int b_sum=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n;j++) {
            if(result[i] && result[j]) {
                a_sum += arr[i][j];
            }
            if(!result[i] && !result[j]) {
                b_sum += arr[i][j];

            }
        }
    }

    diffs = min(diffs, abs(a_sum - b_sum));
}

void backtracking(int index, int cnt) {
    if(cnt == n/2) {
        calcDiff(cnt);

    }
    for(int i=index; i<=n; i++) {
        result[i] = true;
        backtracking(i+1, cnt+1);
        result[i] = false;
    }
}
int main() {
    cin >>n;
    arr.assign(n+1, vector<int>(n+1,0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }


    result.assign(n+1 , false);

    backtracking(1, 0);

    cout << diffs;

    return 0;
}