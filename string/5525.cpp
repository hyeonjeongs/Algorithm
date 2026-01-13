#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    string s;
    cin>> n;
    cin >> m;
    cin >> s;

    string io ="";
    for (int i=0; i<n*2+1; i++) {
        if (i%2==0) {
            io+="I";
        } else {
            io+="O";
        }
    }
    int index= 0, result=0;
    int cnt=0;
    while (index<m) {
        if (s[index] == 'I') {
            cnt =0;
            while (index+2<m && s[index+1]=='O'&& s[index+2]=='I') {
                cnt++;
                if (cnt==n) {
                    result++;
                    cnt--;
                }
                index+=2;
            }
        }
        index++;
    }
    cout << result;
    return 0;
}