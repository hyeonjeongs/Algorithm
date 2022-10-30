#include<iostream>
#include <set>
#include<vector>
#include<algorithm>

using namespace std;

void cycleWord(string str, set<string> &word) {

    for (auto iter: word) {
        //자리수 값 자체가 다르면 다른 단어
        if (iter.size() != str.size())
            continue;
        for (int j = 0; j < str.size(); j++) {
            if (str == iter)
                return;

            //단어 크기 만큼 돌려줌
            rotate(str.begin(), str.begin() + 1, str.end());
        }
    }

    word.insert(str);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<string> word;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        cycleWord(str, word);
    }

    cout << word.size();

    return 0;
}