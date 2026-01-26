#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

struct cmp {
    bool operator()(ll a, ll b) {
        return a>b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll k, input;
        priority_queue<ll, vector<ll>, cmp> pq;
        cin >> k;
        for (int i=0; i<k; i++) {
            cin>> input;
            pq.push(input);
        }
        ll result =0;
        while (pq.size()>=2) {
            long long num = pq.top(); pq.pop();
            ll num2 = pq.top(); pq.pop();
            pq.push(num + num2);
            result += (num + num2);
        }
        cout << result << '\n';

    }
    return 0;
}