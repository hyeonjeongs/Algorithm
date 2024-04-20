#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

vector<vector<int>> dp;

void makeTriangle(vector<vector<int>> triangle){
    dp[0][0] = triangle[0][0];

    for(int i=0; i<triangle.size()-1; i++) {
        for(int j=0; j<triangle[i].size(); j++) {
            dp[i+1][j] = max(dp[i+1][j], triangle[i+1][j]+dp[i][j]);
            dp[i+1][j+1] = max(dp[i+1][j+1], triangle[i+1][j+1]+dp[i][j]);
        }
    }
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    dp.assign(size, vector<int>(size, -1));

    makeTriangle(triangle);
    sort(dp[size-1].begin(), dp[size-1].end(), greater<>());

    answer = dp[size-1][0];
    return answer;
}