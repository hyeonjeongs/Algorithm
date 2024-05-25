#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

typedef long long ll;
using namespace std;
int main() {
    vector<int> num;
    int input;
    ll max_num = 0;
    ll min_num = 1e18;
    do {
        cin>> input;

        num.push_back(input);
    }while(getc(stdin) ==' ');

    sort(num.begin(), num.end());

    string str = "";
    do {
        str = "";
        for(int i=0; i<num.size(); i++) {
            str.append(to_string(num[i]));
        }

        if(stol(str) > max_num) {
            max_num = stol(str);
        }
        if(stol(str) < min_num) {
            min_num = stol(str);
        }
    }while(next_permutation(num.begin(), num.end()));


    cout << max_num + min_num << '\n';

    return 0;
}