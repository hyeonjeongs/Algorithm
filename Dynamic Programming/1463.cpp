#include <iostream>
#include <vector>

using namespace std;
vector<int> num;

void dp(int n) {

    num[1] =0;
    for(int i=2; i<=n; i++){
        num[i] = num[i-1] +1;
        if(i%3==0){
            num[i] = min(num[i/3] +1, num[i]);
        }
        if(i%2==0){
            num[i] = min(num[i/2] +1, num[i]);
        }
    }

    cout<< num[n] <<'\n';

}

int main() {
    int n;

    cin >> n;
    num.assign(n + 1, 0);
    num[n] = 1;
    dp(n);

    return 0;
}