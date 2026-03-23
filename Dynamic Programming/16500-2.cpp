# include <iostream>
# include <vector>

using namespace std;

int main() {
    string s;
    int n;
    vector<string> a;
    cin >> s;
    cin >> n;
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        a.push_back(str);
    }
    vector<bool> dp(s.length()+1 , false);
    dp[s.length()] = true;

    for (int i=s.length()-1; i>=0; i--) {
        for (int j=0; j<n; j++) {
            string str = a[j];
            if (s.length() < str.length() + i) {
                continue;
            }
            string sub = s.substr(i, str.length());
            if (dp[i+str.length()] && sub == str) {
                dp[i] = true;
            }
        }
    }
    cout << dp[0] << '\n';

    return 0;

}