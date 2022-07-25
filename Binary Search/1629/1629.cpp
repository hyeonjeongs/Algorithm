#include <iostream>

using namespace std;
long long divide(int a, int b, int c) {
    if (b == 1)
        return a % c;

    //b Â¦¼ö
    if (b % 2 == 0) { 
        long long sub_problem = divide(a, b / 2, c);
        return (sub_problem * sub_problem) % c;
    }
    //b È¦¼ö
    return (a * divide(a, b - 1, c)) % c; 
}

int main() {
    int a, b, c;

    cin >> a >> b >> c;
    cout << divide(a, b, c);
}