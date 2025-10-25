#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 0;

    while (n>0) {
        if (n%2 ==1) {
            result++;
        }
        n = n/2;
    }
    cout << result << '\n';
    return 0;
}