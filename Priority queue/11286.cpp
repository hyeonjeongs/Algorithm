#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(const int &a, const int &b) {
        if (abs(a) != abs(b))
            return abs(a) > abs(b);
        return a > b;
    }
};

void solve(int input, priority_queue<int, vector<int>, cmp>& pq) {
    if (input == 0) {
        if (pq.empty())
            cout << "0" << '\n';
        else {
            cout << pq.top() << '\n';
            pq.pop();
        }
    } else {
        pq.push(input);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        solve(input, pq);
    }

    return 0;
}