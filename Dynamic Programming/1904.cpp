/*
 * 주의할점
 * 숫자 크기 long long 보다 커지게 됨
 */

#include <iostream>
#include <vector>

using namespace std;

int binaryNum(int n){
    vector<long long> dp (n+1,0);
    long long tmp;

    dp[1] =1;
    dp[2] =2;

    for(int i=3; i<=n; i++){
        tmp = dp[i-1] + dp[i-2];
        dp[i] = tmp%15746;
    }

    return dp[n];
}

int main(){
    int n;

    cin>> n;

    cout<< binaryNum(n)%15746<<'\n';

    return 0;
}