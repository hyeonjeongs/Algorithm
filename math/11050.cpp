#include <iostream>

using namespace std;


//팩토리얼 함수
int fac(int n) {
    if (n == 0)
        return 1;
    return n * fac(n - 1);
}

int main() {
    int n, k;

    cin >> n >> k;

    int ans = fac(n) / (fac(n - k) * fac(k));

    cout << ans << '\n';

    return 0;
}