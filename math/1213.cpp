#include<iostream>
#include<map>
#include<cstdio>
#include<string>
using namespace std;
string name, str;
char mid;
int fail;

int main() {
    map<char, int,greater<char>> _map;
    cin >> name;
    for (char c : name) {
        _map[c]++;
    }

    for (auto iter : _map) {
        if (iter.second % 2 == 1) {
            mid += iter.first;
            fail++;
            iter.second--;
        }
        if (fail == 2) break;
        for (int j = 0; j < iter.second; j += 2) {
            str = iter.first + str;
            str += iter.first;
        }
    }
    if (mid) str.insert(str.begin() + str.size() / 2, mid);
    if (fail == 2) cout << "I'm Sorry Hansoo";
    else cout << str;
    return 0;
}