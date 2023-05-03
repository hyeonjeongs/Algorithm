#include <iostream>
#include <vector>
const int MAX = 1E6;
using namespace std;
vector<pair<int, int>> minNum(int n){
    vector<pair<int, int>> dp(n+1, pair<int,int>(MAX,0)); // 첫번째는 연산횟수, 두번째는 전에 index
    dp[1].first = 0;
    dp[1].second = 0;

    for(int i=1; i<=n; i++){
        if(i*3 <= n && dp[i*3].first > dp[i].first+1){
            dp[i*3].first = dp[i].first+1;
            dp[i*3].second = i;
        }
        if(i*2 <= n && dp[i*2].first > dp[i].first+1){
            dp[i*2].first = dp[i].first+1;
            dp[i*2].second = i;
        }
        if(i+1<=n && dp[i+1].first > dp[i].first+1){
            dp[i+1].first = dp[i].first+1;
            dp[i+1].second = i;
        }
    }

    return dp;
}

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>> result = minNum(n);
    cout<< result[n].first<<'\n';

    int idx = n;
    cout<< n<<' ';
    while(1){
        if(idx==1){
            break;
        }
        cout<<result[idx].second<<' ';
        idx= result[idx].second;
    }

    return 0;
}