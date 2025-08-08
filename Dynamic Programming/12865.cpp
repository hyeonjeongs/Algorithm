#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
vector<int> dp;
vector<pi> bags;
int n, k;
void findWeight() {

    for(int i=0; i<n; i++) {
        for(int j=k; j>=bags[i].first;j--) {
            dp[j] =max(dp[j], bags[i].second + dp[j-bags[i].first]);
        }
    }
}
int main() {

    cin >>n>>k;
    dp.assign(k+1, 0);
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        bags.push_back({a, b});
    }
    findWeight();
    cout << dp[k];
    return 0;

}

/*
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
int dp[100001];
int n, k;
int findNum(vector<pi> arr) {

    for(int i=0; i<arr.size(); i++) {
        for(int j=k; j>=arr[i].first; j--) {
            dp[j] = max(dp[j], arr[i].second + dp[j- arr[i].first]);
        }
    }
    return dp[k];
}

int main() {

    cin >> n>>k;
    vector<pi> arr(n, {0,0});

    for(int i=0; i<n; i++) {
        int w, v;
        cin >> w >> v;
        arr.push_back({w, v});
    }
    cout << findNum(arr);
    return 0;

}
*/