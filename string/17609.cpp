#include <iostream>
#include <vector>
#include <string>

using namespace std;

int checkSpin(string str) {
    int sizes = str.size();
    vector<bool> checked(sizes, false);

    string currents = str;
    int result = 0;
    for(int i=0; i<sizes/2; i++) {
        if(str[i] != str[sizes-i-1]) {
            result = -1;
            break;
        }
    }
    if(result == 0) {
        return result;
    }

    for(int i=0; i<sizes; i++) {
        string copy1 = currents;
        string copy2 = currents;
        currents = copy.substr(0,) + copy.substr(i+1);
    }

}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        cout << checkSpin(str) << '\n';
    }
    return 0;
}