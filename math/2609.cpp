#include <iostream>

using namespace std;

int gcdBad(int a, int b) {
    for (int i = min(a, b); i > 1; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1; //끝까지 없다면 최대공약수 1
}


int gcdRecursion(int a, int b) {
    if (b == 0)
        return a;

    return gcdRecursion(b, a % b);
}

int main() {
    int a, b;

    cin >> a >> b;

    int g = gcdRecursion(max(a, b), min(a, b));
    int l = (a * b) / g;

    cout << g << '\n' << l << '\n';

    return 0;
}