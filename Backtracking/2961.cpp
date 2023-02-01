#include <iostream>
#include <vector>

using namespace std;
#define INF 1000000000

vector<pair<int, int>> flavor;
void diffFlavor(int n) {
    int ans = INF;
    for (int i = 1; i < (1 << n); i++) {
        int sour = 1, bitter = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sour *= flavor[j].first;
                bitter += flavor[j].second;
            }
        }
        ans = min(ans, abs(sour - bitter));
    }

    cout << ans;
}
int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int sour, bitter;
        cin >> sour >> bitter;
        flavor.push_back({sour,bitter});
    }

    diffFlavor(n);
    return 0;
}

