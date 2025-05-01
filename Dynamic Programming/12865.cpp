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


/*#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
vector<int> dp;
int findWeight(vector<pi> bags, int k, int n) {

    for(int i=0; i<n; i++) {
        for(int j=k; j>=bags[i].first; j--) {
            dp[j] = max(dp[j], bags[i].second + dp[j - bags[i].first]);
        }
    }
    return dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<pi> bags(n, pi(0,0));
    dp.assign(100001, 0);

    for(int i=0; i<n; i++) {
        cin >> bags[i].first >> bags[i].second;
    }

    cout << findWeight(bags, k, n);

    return 0;

}*/











/*
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int maxPack(int n, int k, vector<pi> &product) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) { // i : 현재 넣으려는 물품
        for (int j = 0; j < product[i].first; j++) { // 현재 물품의 무게-1 만큼 전 행꺼 가져옴
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = product[i].first; j <= k; j++) { // 이제 현재 무게를 시작으로 배낭에 넣을지 결정

            // 무게에 따라 넣을 수 있는 것이 현재 무게랑 합했을 때 작은 놈이라 (j - 현재 물품 무게)로 설정
            dp[i][j] = max(dp[i - 1][j - product[i].first] + product[i].second, dp[i - 1][j]); // 앞에꺼가 크면 배낭에 넣는 경우, 뒤에꺼가 크면 배낭에 안넣음
        }
    }

    return dp[n][k];
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<pi> product(n+1, pi(0,0));

    for (int i = 1; i <= n; i++) {
        cin >> product[i].first >> product[i].second;
    }

    cout << maxPack(n, k, product);
    return 0;
}*/

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