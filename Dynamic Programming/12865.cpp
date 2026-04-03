#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
// 무게 k일 때 가치가 가장 높은 것
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(k+1, 0);
    vector<pi> weight(n,pi(0,0));


    for(int i=0; i<n; i++) {
        int v, w;
        cin >> w >> v;
        weight.push_back({w,v});
    }



    for(int i=0; i<weight.size(); i++) {
        for(int j=k; j>=weight[i].first; j--) {
            dp[j] = max(dp[j], dp[j-weight[i].first] + weight[i].second);
        }
    }

    cout << dp[k] << '\n';

    return 0;
}

// #include <iostream>
// #include <vector>
//
// using namespace std;
// typedef pair<int, int> pi;
// vector<int> dp;
// vector<pi> bags;
// int n, k;
// void findWeight() {
//
//     for(int i=0; i<n; i++) {
//         for(int j=k; j>=bags[i].first;j--) {
//             dp[j] =max(dp[j], bags[i].second + dp[j-bags[i].first]);
//         }
//     }
// }
// int main() {
//
//     cin >>n>>k;
//     dp.assign(k+1, 0);
//     for(int i=0; i<n; i++) {
//         int a, b;
//         cin >> a >> b;
//         bags.push_back({a, b});
//     }
//     findWeight();
//     cout << dp[k];
//     return 0;
//
// }

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