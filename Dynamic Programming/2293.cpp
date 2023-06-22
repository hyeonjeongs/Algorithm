// 동전 (DP)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int makeCoin(vector<int> coin, int n, int k){
    vector<int> dp(k+1, 0);

    dp[0] = 1; // 아무 동전 선택 안한 경우의 수 -> 1가지
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            // coin[i]원으로 j원 만들기 위해 [j-coin[i]]원 만드는 경우의 수를 더해줘야함
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