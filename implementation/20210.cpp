#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
    
}

int main() {
    int n;
    vector<string> str;
    cin >> n;
    for(int i=0; i<n; i++) {
        string input;
        cin >> input;
        str.push_back(input);
    }
    sort(str.begin(), str.end(), cmp);

    for(int i=0; i<n; i++) {
        cout << str[i] << "\n";
    }

    return 0;
}
