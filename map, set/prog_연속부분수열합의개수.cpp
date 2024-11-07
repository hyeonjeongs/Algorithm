#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    set<int> num;
    int size = elements.size();
    vector<int> dp(size+1, 0);
    dp[0] = 0;

    for(int i=1; i<=size; i++) {
        dp[i] = dp[i-1] + elements[i-1];
    }
    // 7 16 17 18 22
    for(int i=0; i<size; i++) {
        for(int j=1; j<=size; j++) {
            int number = 0;
            if(j+i >size) {
                number = (dp[size]-dp[j-1]) + dp[(i+j-1)%size];
            }else {
                number = dp[j+i] - dp[j-1];
            }
            num.insert(number);
        }
    }
    answer = num.size();

    return answer;
}