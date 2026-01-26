#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<pi> v;

    for (int i=0; i<n; i++) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        pq.push(v[i].second);
        if (pq.size() > v[i].first) {
            pq.pop();
        }
    }

    ll result = 0;
    while (!pq.empty()) {
        result += pq.top();
        pq.pop();
    }
    cout << result << '\n';
   return 0;
}