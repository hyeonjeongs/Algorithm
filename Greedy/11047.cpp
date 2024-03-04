#include<iostream>
#include<vector>

using namespace std;

int minNum(int n, int k, vector<int> coin) {
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (k == 0)
            break;
        cnt += k / coin[i]; //코인 개수
        k %= coin[i]; //남은 돈
    }
    
    return cnt;
    
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coin(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    cout << minNum(n, k, coin);
    return 0;
}

