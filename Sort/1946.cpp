#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> ci;

int maxMembers(vector<ci> &members, int n) {
    int cnt = 1;
    int rank = members[0].second;

    for (int i = 0; i < n; i++) {
        if (members[i].second < rank) {
            cnt++;
            rank = members[i].second;
        }
    }

    return cnt;
}

int main() {
    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<ci> members(n, ci(0, 0));
        for (int i = 0; i < n; i++) {
            cin >> members[i].first >> members[i].second;
        }
        sort(members.begin(), members.end()); //순서 오름차순 정렬
        cout << maxMembers(members, n) << '\n';
    }

    return 0;
}
