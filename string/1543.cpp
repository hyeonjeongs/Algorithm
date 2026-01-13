#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str, word;
    getline(cin, str);
    getline(cin, word);
    vector<int> dp(str.size()+1, 0);
    if (word.size() > str.size()) {
        cout << 0;
        return 0;
    }

    for (int i=1; i<=str.size(); i++) {
        dp[i] = max(dp[i], dp[i-1]);

        if (i>=word.size()) {
            string current = str.substr(i-word.size(), word.size());
            if (current == word) {
                dp[i] = max(dp[i], dp[i-word.size()]+1);
            }
        }

    }

    cout << dp[str.size()];
    return 0;
}