#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<int> dp;
int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    dp.assign(n, 1e7);
    vector<int> idxB;
    vector<int>idxO;
    vector<int> idxJ;
    for(int i=0; i<n; i++) {
        if(str[i]=='B') {
            idxB.push_back(i);
        } else if(str[i]=='O') {
            idxO.push_back(i);
        } else if(str[i]=='J') {
            idxJ.push_back(i);
        }
    }

    dp[0]=0;
    for(int i=0; i<n; i++) {
        if(str[i] == 'B') {
            for(int j=0; j<idxJ.size(); j++) {
                if(idxJ[j]<i) {
                    if(dp[idxJ[j]]!=1e6) {
                        int diff =  pow(i-idxJ[j], 2) + dp[idxJ[j]];
                        dp[i] = min(dp[i],diff);
                    }

                } else {
                    break;
                }
            }
        }
        if(str[i] == 'O') {
            for(int j=0; j<idxB.size(); j++) {
                if(idxB[j]<i) {
                    if(dp[idxB[j]]!=1e7) {
                        int diff =  pow(i-idxB[j], 2) + dp[idxB[j]];
                        dp[i] = min(dp[i],diff);
                    }

                } else {
                    break;
                }
            }

        }
        if(str[i] == 'J') {
            for(int j=0; j<idxO.size(); j++) {
                if(idxO[j]<i) {
                   if(dp[idxO[j]]!=1e7) {
                       int diff =  pow(i-idxO[j], 2) + dp[idxO[j]];
                       dp[i] = min(dp[i],diff);
                   }
                } else {
                    break;
                }
            }

        }
    }
    if(dp[n-1]== 1e7) {
        cout << -1 << '\n';
    } else {
        cout << dp[n-1] << '\n';
    }

    return 0;
}