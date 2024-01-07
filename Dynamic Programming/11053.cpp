#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dp(int n, vector<int>& a){
    vector<int> num(n, 1);
    int result = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            //증가하고 있는 경우 현재값과 전에것과 더해진 값중 더 큰값 저장하기
            if(a[i] > a[j]){
                num[i] = max(num[j]+1, num[i]);
            }
        }
        result = max(result, num[i]);
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n, 0);

    for(int i=0; i<n; i++){
        cin>> a[i];
    }

    cout<<dp(n, a);
    return 0;
}
