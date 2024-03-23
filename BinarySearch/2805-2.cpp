#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll binarySearch(ll n, ll m, vector<ll> tree) {

    ll left = 0;
    ll right = tree[n-1];

    ll cnt =0;

    while(left <= right) {
        ll mid= (left + right)/2;
        ll result = 0;
        ll index = lower_bound(tree.begin(), tree.end(), mid) - tree.begin();

        for(int i=index; i<n; i++) {
            result += (tree[i]-mid);
        }
        if(result>=m){
            cnt = max(cnt, mid);
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return cnt;
}

int main() {

    ll n, m;
    cin>>n>>m;

    vector<ll> tree(n,0);

    for(int i=0; i<n; i++) {
        cin>> tree[i];
    }
    sort(tree.begin(), tree.end());

    cout<<binarySearch(n, m, tree);
    return 0;
}