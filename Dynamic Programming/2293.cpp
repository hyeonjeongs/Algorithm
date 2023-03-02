// 동전 (DP)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int makeCoin(vector<int> coin, int n, int k){
    vector<int> dp(k+1, 0);

    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j] += dp[j-coin[i]]; // 2원을 이용하고 10원을 만드는 경우 [8]원에 저장된 데이터를 저장함
        }
    }
    return dp[k];
}

int main(){
    int n, k;

    cin>>n>>k;
    vector<int> coin(n,0);

    for(int i=0; i<n; i++){
        cin>>coin[i];
    }

    cout<<makeCoin(coin,n,k)<<"\n";

    return 0;
}