// programmers
// https://school.programmers.co.kr/learn/courses/30/lessons/1829

#include <vector>
#include <iostream>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
vector<vector<bool>> visit;

int cnt=1;

void dfs(int x, int y, int m, int n, vector<vector<int>> picture){

    visit[y][x] = true;
    
    for(int i=0; i<4; i++){
        int new_x = x+ dx[i];
        int new_y = y+ dy[i];

        if(new_x>=0 && new_x<n && new_y >=0 && new_y <m
           && !visit[new_y][new_x] && picture[new_y][new_x] == picture[y][x]){
            dfs(new_x, new_y, m, n, picture);
            cnt++;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    visit.assign(m, vector<bool>(n,0));



    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!visit[i][j] && picture[i][j]>0){
                dfs(j, i, m, n, picture);
                number_of_area++;
                max_size_of_one_area = max(cnt,max_size_of_one_area);
            }
            cnt=1;
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}