#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num=0, x;
    vector<int> arr;

    cin >> x;

    while(x>0) {
        if(x%2==1) {
            num++;
        }
        x = x/2;
    }
    cout << num << '\n';

    return 0;
}