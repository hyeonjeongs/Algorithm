#include <iostream>
#include <vector>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> stairs(n, 0);
    for (int i=0; i<n; i++) {
        cin >> stairs[i];
    }

    vector<int> dp(n+1, 0);
    dp[1] = stairs[0];
    dp[2] = stairs[1] + stairs[0];

    for (int i=3; i<=n; i++) {
        dp[i] = stairs[i-1] + max(dp[i-2], dp[i-3]+stairs[i-2]);
    }
    cout << dp[n] << '\n';
    return 0;
}


/*
#include <iostream>
#include <vector>

using namespace std;

int dp(vector<int> stairs, int n) {
    vector<int> number(n+1,0);

    number[1] = stairs[0];
    number[2] = stairs[1] + number[1];
    for(int i=3; i<=n ;i++){
        number[i] = max(number[i-2], number[i-3]+stairs[i-2]) + stairs[i-1];
    }
    return number[n];
}

int main() {
    int n;
    cin>>n;
    vector<int> stairs;

    for(int i=0; i<n; i++) {
        int input;
        cin >>input;
        stairs.push_back(input);
    }

    cout<<dp(stairs,n);

    return 0;
}
*/


/*
#include <iostream>
#include <vector>

using namespace std;

int stairsScore(vector<int> &stairs, int n){
    vector<int> dp(n+1,0);

    dp[1] = stairs[0];
    dp[2]= stairs[0] + stairs[1];
    for(int i=3; i<=n; i++){
        dp[i] = max(dp[i-2], dp[i-3]+stairs[i-2]) + stairs[i-1];
    }

    return dp[n];
}

int main(){
    int n;
    cin>> n;
    vector<int> stairs (n,0);

    for(int i=0; i<n; i++){
        cin >> stairs[i];
    }

    cout<< stairsScore(stairs, n);

    return 0;
}
*/
