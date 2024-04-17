#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    unsigned int m;
    cin>>m;
    string str;
    int num=0;
    int result = 0;

    while(m--) {
        cin >> str;
        if(str == "add"){
            cin >> num;
            result |= (1<<num);
        } else if(str == "remove") {
            cin >> num;
            result &= ~(1<<num);
        } else if(str == "check") {
            cin >> num;
            if(result & (1<<num)){
                cout << 1 <<'\n';
            } else {
                cout << 0 <<'\n';
            }
        } else if(str == "toggle") {
            cin >> num;
            result ^= (1<<num);
        } else if(str == "all") {
            result = (1<<21) -1;
        } else {
            result = 0;
        }

    }
    return 0;
}