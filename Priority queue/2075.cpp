#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;
    vector<vector<ll>> number;
    priority_queue<int, vector<int>, greater<>> pq;

    for(int i=0; i<n*n; i++) {
        int num;
        cin>>num;
        pq.push(num);
        if(pq.size() >n) {
            pq.pop();
        }
    }
    cout<<pq.top();

    return 0;
}