#include <iostream>
#include <vector>

using namespace std;

int main() {

    int left = 1, right = 1;

    int n, s;
    cin>>n>>s;
    int cnt = n+1;

    vector<int> num(n+1, 0);
    for(int i=1; i<=n; i++) {
        int input;
        cin >> input;
        num[i] = input + num[i-1];
    }

    while(left<=right && right<=n){
        int number = num[right] - num[left-1];
        int length = right - left +1;
        if(number >= s) {
            cnt = min(cnt, length);
            left++;
        }
        else {
            right++;
        }
    }

    if(cnt == n+1) {
        cnt =0;
    }

    cout << cnt <<'\n';
    return 0;
}