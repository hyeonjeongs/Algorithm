#include<iostream>
#include<vector>

using namespace std;
int fibo[10001];
void dp(int n) {
    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i <= n; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    cout<<fibo[n];

}
int main() {
    int n;
    cin >> n;


    dp(n);

    return 0;
}