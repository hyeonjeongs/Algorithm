#include <iostream>
#include <vector>
#include <string>

using namespace std;
string strs;

int isCheck(int left, int right, bool isUse) {
    while(left < right) {
        if(strs[left] != strs[right]) {
            if(isUse) {
                if(isCheck(left+1, right, false) == 0 || isCheck(left, right-1, false) == 0) {
                    return 1;
                }
            }
            return 2;
        }
        left++; right--;
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {

        cin >> strs;
        cout << isCheck(0, strs.size()-1, true) << '\n';
    }
    return 0;
}