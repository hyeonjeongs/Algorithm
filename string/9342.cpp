#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool checkString(string str) {
    int currents=0;
    if(str.size()==0) {
        return true;
    }

    for(int i=0; i< str.size(); i++) {
        int nums = str[i] - 65;

        if (i == 0 || i == str.size() - 1) {
            if (nums < 0 || nums > 5) {
                return false;
            }
        } else {
            if (nums != 0 && nums != 5 && nums != 2) {
                return false;
            }
        }

        if (nums == 0) {
            if (currents == 0 || currents == 1) {
                currents = 1;
            } else {
                return false;
            }
        } else if (nums == 5) {
            if (currents == 1 || currents == 2) {
                currents = 2;
            } else {
                return false;
            }
        } else if (nums == 2) {

            if (currents == 2 || currents == 3) {
                currents = 3;

            } else {
                return false;
            }
        }
    }

    if(currents!=3) {
        return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    for(int i=0; i<t; i++) {
        string str;
        cin >>str;
        if(checkString(str)) {
            cout << "Infected!" << '\n';
        } else {
            cout << "Good" << '\n';
        }
    }
    return 0;
}