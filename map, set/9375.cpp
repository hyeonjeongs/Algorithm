#include <iostream>
#include <map>

using namespace std;

int clothNum(map<string, int> clothes) {
    int result = 1;
    for (auto iter: clothes) {
        result *= iter.second + 1;
    }
    result -= 1; // 알몸 경우

    return result;
}

int main() {
    int t, n;
    string cloth, type;

    cin >> t;
    while (t--) {
        cin >> n;
        map<string, int> clothes;
        for (int i = 0; i < n; i++) {
            cin >> cloth >> type;
            clothes[type]++; //옷 종류 수 저장
        }

        cout << clothNum(clothes) << '\n';
    }
    return 0;
}