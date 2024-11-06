#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int i=0; i<n; i++) {
        cin >>a[i];
    }

    for(int i=0; i<n; i++) {
        cin >>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    int result = 0;
    for(int i=0; i<n; i++) {
        result += a[i] * b[i];
    }
    cout << result << '\n';

    return 0;
}