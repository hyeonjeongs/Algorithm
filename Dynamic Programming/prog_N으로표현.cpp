#include <string>
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;

int insertN(int N, int  k) {
    int result = N;
    for(int i=1; i<k; i++) {
        result = result* 10 + N;
    }
    return result;
}

int solution(int N, int number) {
    int answer = 0;
    vector<unordered_set<int>> dp(9);

    if(N==number) {
        return 1;
    }

    dp[0].insert(0);
    dp[1].insert(N);
    for(int k=2; k<=8; k++) {

        dp[k].insert(insertN(N, k));

        for(int p=1; p<k; p++) {
            for(int i : dp[p]) {
                for(int j : dp[k-p]) {
                    dp[k].insert(i+j);
                    dp[k].insert(i*j);
                    if(i>j) {
                        dp[k].insert(i-j);
                    }
                    if(j !=0) {
                        dp[k].insert(i/j);
                    }

                }
            }
        }
        if(dp[k].find(number) != dp[k].end()) {
            return k;
        }
    }



    return -1;
}


/*
#include <string>
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;

int insertN(int N, int  k) {
    int result = N;
    for(int i=1; i<=k; i++) {
        result = result* 10 + N;
    }
    return result;
}

int solution(int N, int number) {
    int answer = 0;
    vector<unordered_set<int>> dp(8);

    if(N==number) {
        return 1;
    }

    dp[0].insert(N);
    for(int k=1; k<8; k++) {

        dp[k].insert(insertN(N, k));

        for(int p=0; p<k; p++) {
            for(int i : dp[p]) {
                for(int j : dp[k-p-1]) {  // 여기 index 가 헤깔 (위에처럼 풀면 index 덜헤깔림)
                    dp[k].insert(i+j);
                    dp[k].insert(i*j);
                    if(i>j) {
                        dp[k].insert(i-j);
                    }
                    if(j !=0) {
                        dp[k].insert(i/j);
                    }

                }
            }
        }
        if(dp[k].find(number) != dp[k].end()) {
            return k+1;
        }
    }



    return -1;
}
*/
