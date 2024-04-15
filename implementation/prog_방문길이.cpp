#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <cstring>

#define MAX_SIZE 11
using namespace std;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

bool outOfBounds(int x, int y) {
    return !(x>=0 && x<=10 && y>=0 && y<=10);
}

int solution(string dirs) {
    int answer = 0;
    bool visited[11][11][4];
    memset(visited, false, sizeof(visited));

    int x = 5;
    int y = 5;

    int dir = 0;
    for(int i=0; i<dirs.size(); i++) {

        if(dirs[i]== 'U'){
            dir = 0;

        } else if(dirs[i] =='D') {
            dir = 2;

        } else if(dirs[i] == 'R') {
            dir = 1;

        } else {
            dir = 3;

        }
        int direction = (dir +2)%4;
        int nx = x+ dx[dir];
        int ny = y+dy[dir];
        if(outOfBounds(nx, ny)){
            continue;
        }
        if(!visited[ny][nx][dir]) {
            visited[ny][nx][dir] = true;
            visited[y][x][direction] = true;
            answer++;
        }
        x=nx;
        y=ny;
    }

    return answer;
}