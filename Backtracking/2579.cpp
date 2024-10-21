#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int k;
    cin >>k;

    vector<char> arrow(k, ' ');
    vector<int> num(10,0);

    for(int i=0; i<k; i++) {
        cin >> arrow[i];
    }
    for(int i=0; i<10; i++) {
        num[i] = i;
    }

    sort(num.begin(), num.end());
    long long min_num = 9999999999;
    long long max_num = 0;
    string min_str = "";
    string max_str = "";
    // 0 1 2 3 4 5
    do {
        int cnt = 0;
        string num_str="";
        for(int i=0; i<k; i++) {
            int left = num[i];
            int right = num[i+1];
            if(arrow[i] == '<') {
                if(left > right) {
                    break;
                }
            } else {
                if(left < right) {
                    break;
                }
            }
            num_str += to_string(num[i])[0];

            cnt++;
        }
        if(cnt==k) {
            num_str += to_string(num[k])[0];
            if(stoll(num_str) > max_num) {
                max_num = stoll(num_str);
                max_str = num_str;
            }
            if(stoll(num_str) < min_num) {
                min_num = stoll(num_str);
                min_str = num_str;
            }
        }
    }while(next_permutation(num.begin(), num.end()));

    cout << max_str <<'\n';
    cout << min_str << '\n';
    return 0;
}