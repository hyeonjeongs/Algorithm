#include <iostream>
#include <vector>

using namespace std;

int addNum(int input){
    vector<int> dp(12,0);

    dp[1]=1; dp[2]=2; dp[3]=4;

    for(int i=4; i<=input; i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }

    return dp[input];
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int input;
        cin>> input;
        cout<<addNum(input)<<'\n';
    }
}