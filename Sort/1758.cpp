/*
 * long long type 때문에 오류 났음
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll maxTips(vector<int> &tips, int n) {
    ll maxTip=0;

    for(int i=1; i<=n; i++) {
        int num = tips[i-1] - (i-1);
        if(num <0){
            break;
        }
        maxTip += num;
    }
    return maxTip;
}

int main() {
    int n;
    cin>>n;

    vector<int> tips(n,0);

    for(int i=0; i<n; i++) {
        cin>>tips[i];
    }

    sort(tips.begin(), tips.end(), greater<>());
    cout<<maxTips(tips, n);

    return 0;
}