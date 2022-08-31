#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

void solve(int num) {
    if (num == 0) {
        if (!pq.empty()) {
            cout << pq.top() << '\n';
            pq.pop();
        }
        else {
            cout << 0 << '\n';
        }
    }
    else {
        pq.push(num);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        solve(input);
    }

    return 0;
}