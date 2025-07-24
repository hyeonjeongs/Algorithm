#include <iostream>
#include <vector>
using namespace std;

vector<int> remote(10, 0);
int n,m;
bool findNumber(int num) {

    string str = to_string(num);
    for(int i=0; i<str.size(); i++) {
        if(remote[str[i] - '0'] ==1) {
            return false;
        }
    }
    return true;
}

int main() {

    cin >> n;
    cin >> m;

    for(int i=0; i<m; i++) {
        int input;
        cin >>input;
        remote[input] = 1;
    }

    int result = abs(100 - n);

    for(int i=0; i<1000000; i++) {
        if(findNumber(i)) {
            int numbers = abs(n - i) + to_string(i).size();
            result = min(result, numbers);
        }
    }



    cout << result << '\n';

    return 0;
}