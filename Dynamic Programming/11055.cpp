#include <iostream>
#include <vector>

using namespace std;

// 현재 index까지 올 수 있는 최대값
// 전에 값도 받아서 증가하는게 맞나 확인
int maxSequence(int n, vector<int> &sequence){
    vector<int> dp(n, 0);
    int result =0;
    for(int i=0; i<n; i++){
        dp[i] = sequence[i]; // 이부분 첨에 안해서 틀림
        for(int j=0; j<i; j++){
            if(sequence[j] < sequence[i]){
                dp[i] = max(dp[i], sequence[i] + dp[j]);
            }
        }
        result = max(result,dp[i]);
    }
    return result;
}

int main(){
    int n;

    cin >> n;
    vector<int> sequence(n, 0);

    for(int i=0; i<n; i++){
        cin>> sequence[i];
    }

    cout<< maxSequence(n, sequence);
    return 0;
}