#include<iostream>
#include<set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> num;

    int input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        num.insert(input);
    }

    for (auto iter: num) {
        cout << iter << ' ';
    }

    return 0;
}