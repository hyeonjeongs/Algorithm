#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> words;

bool cmp(string a, string b) {
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int num;
    string word;

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> word;
        words.push_back(word);
    }

    sort(words.begin(), words.end(), cmp);

    cout << words[0] << '\n';
    for (int i = 1; i < num; i++) {
        if (words[i] == words[i - 1])
            continue;
        cout << words[i] << '\n';
    }
}
