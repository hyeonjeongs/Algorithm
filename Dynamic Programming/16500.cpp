#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    int n;
    string s;
    cin >>s;
    cin >> n;
    vector<string> arr;

    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        arr.push_back(str);
    }
    bool dp[s.length()+1];
    memset(dp, false, sizeof(dp));
    dp[s.length()] = true;

    for (int i = s.length(); i>=0; i--) {
        for (int j=0; j<n; j++) {
            if (s.length() < arr[j].length() + i) {
                continue;
            }
            if (s.find(arr[j], i) == i && dp[i+arr[j].length()]==1) {
                dp[i] = 1;
            }
        }
    }
    cout << dp[0] << endl;
    return 0;
}