#include <iostream>
#include <vector>

using namespace std;

//유클리드 호제법
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

//가능한 모든 쌍의 최대공약수의 합 구하는 함수
long long gcdSum(int n, vector<int> &v) {
    long long ans = 0;

    //가능한 모든 쌍의 최대공약수 구한 후 ans 에 더하기
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int g = gcd(max(v[i], v[j]), min(v[i], v[j]));
            ans += g;
        }
    }

    return ans;
}
int main() {
    int t, n;

    //입력
    cin >> t;

    //입력 + 연산
    while (t--) {
        cin >> n;

        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        //출력
        cout << gcdSum(n, v) << '\n';
    }
    return 0;
}