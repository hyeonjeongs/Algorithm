#include<iostream>
#include<vector>

typedef long long ll;
using namespace std;

ll minInspector(vector<int> candidate, int n, int b, int c) {
    ll cnt = n;

    for (int i = 0; i < n; i++) {
        int sub_inspector = candidate[i] - b;
        if (sub_inspector <= 0)
            continue;
        cnt += sub_inspector / c;
        if (sub_inspector % c != 0)
            cnt++;
    }

    return cnt;
}

int main() {
    int n, b, c;

    cin >> n;

    vector<int> candidate(n, 0);

    for (int i = 0; i < n; i++)
        cin >> candidate[i];
    cin >> b >> c; //총감독관, 부감독관

    cout << minInspector(candidate, n, b, c) << '\n';

    return 0;
}