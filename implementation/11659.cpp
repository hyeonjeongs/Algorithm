#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, m;

    cin>>n>>m;
    vector<long long> num(n+1,0);

    long long nums;
    for(int i=1; i<=n; i++) {
        cin>> nums;
        num[i] = num[i-1] + nums;;
    }

    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a>>b;
        cout << num[b] - num[a-1]<< '\n';
    }
    return 0;

}