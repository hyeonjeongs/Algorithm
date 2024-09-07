#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct NODE{
    int x;
    int y;
};
// 막혀있는 경우, 거리가 2 보다 큰 경우 (거리두기 성공)
// 그사람이 갈 수 있니, 찾더라도 거리가 2보다 크면 끝내기
int dx[] ={-1,1,0,0};
int dy[] = {0,0,1,-1};

int distSize(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

bool bfs(vector<vector<char>> interviewer, int x, int y) {
    queue<NODE> que;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx<0 || nx>=5 || ny<0 || ny>=5 || interviewer[ny][nx] =='X') {
            continue;
        }

        if(interviewer[ny][nx] =='P') {
            return false;
        }

        que.push({nx, ny});
    }

    while(!que.empty()) {
        int cx = que.front().x;
        int cy = que.front().y;
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx<0 || nx>=5 || ny<0 || ny>=5) {
                continue;
            }
            if(nx==x && ny==y) {
                continue;
            }

            if(interviewer[ny][nx] =='P' && distSize(x, y, nx, ny)<=2) {
                return false;
            }

        }
    }
    return true;

}

bool followRule(vector<vector<char>> interviewer) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(interviewer[i][j] =='P') {
                if(bfs(interviewer, j, i)) {
                    return true;
                }else {
                    return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int i=0; i<places.size(); i++) {
        vector<vector<char>> interviewer(5, vector<char>(5,' '));

        for(int j=0; j<5; j++) {
            string str = places[i][j];
            for(int k=0; k<5; k++) {
                interviewer[j][k] = str[k];
            }
        }

        if(followRule(interviewer)) {
            answer.push_back(1);
        }else {
            answer.push_back(0);
        }
    }

    return answer;
}