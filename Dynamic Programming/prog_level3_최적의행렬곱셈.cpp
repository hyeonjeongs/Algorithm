// 23.11.02 다시 풀어보기 !

# include <string>
# include <vector>
# include <iostream>

using namespace std;

int dp[201][201];
vector<vector<int>> matrix;

int minNumber(int start, int end);

int find(int start, int end) {
    if(dp[start][end] == 0) {
        dp[start][end] = minNumber(start, end);
    }
    return dp[start][end];
}


int minNumber(int start, int end) {

    int mins = 1e9;

    if(end-start <=1) {
        return 0;
    }

    for(int i=start+1; i<end; i++) {
        int left = find(start, i);
        int right = find(i, end);
        int current = matrix[start][0]*matrix[i][0]*matrix[end-1][1];
        mins = min(mins, left+right+current);
    }

    return mins;
}

int solution(vector<vector<int>> matrix_sizes) {

    int answer = 0;
    int size = matrix_sizes.size();
    matrix = matrix_sizes;

    answer = minNumber(0, size);

    return answer;
}