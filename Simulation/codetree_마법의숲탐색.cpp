#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

struct NODE {
    int x;
    int y;
    int dir;
};

int dx[]= {0,1,0,-1}; // 북 동 남 서
int dy[]= {-1,0,1,0};

vector<vector<int>> wood;
int row_total=0; // 답
int number=1; // 현재 정령 할당된 개수
bool movePossible = false;
int dir =0;

int r, c, k;

bool outOfRange(int x, int y) {
    return x<=0 || x>c || y<0 || y>r+2;
}
bool outOfWoodRange(int x, int y) {
    return x<=0 || x>c || y<=2 || y>r+2;
}

pi moveSouth(pi horse) {
    bool isPossible = true;
    int cx = horse.first;
    int cy = horse.second;
    while(true) {
        if(!isPossible || cy==r+1) {
            break;
        }
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i] + 1;
            if(wood[ny][nx]!=0){
                isPossible = false;
                break;
            }
        }
        if(isPossible) {
            cy+=1;
        }
    }
    return pi(cx, cy);
}

pi moveAndLeftSpin(pi horse) { // 서쪽이동 -> 반시계 회전
    bool isPossible = true;
    int cx = horse.first;
    int cy = horse.second;
    for(int i=0; i<4; i++) {
        int nx = cx + dx[i] - 1;
        int ny = cy + dy[i];
        if(outOfRange(nx, ny) || wood[ny][nx]!=0){
            isPossible = false;
            break;
        }
        ny += 1;
        if(outOfRange(nx, ny) || wood[ny][nx]!=0){
            isPossible = false;
            break;
        }
    }
    if(isPossible) {
        cy+=1;
        cx-=1;
        dir-=1;
        if(dir<0) {
            dir =3;
        }
    }
    return pi(cx, cy);
}

pi moveAndRightSpin(pi horse) { // 동쪽이동 -> 시계회전
    bool isPossible = true;
    int cx = horse.first;
    int cy = horse.second;
    for(int i=0; i<4; i++) {
        int nx = cx + dx[i] + 1;
        int ny = cy + dy[i];
        if(outOfRange(nx, ny) || wood[ny][nx]!=0){
            isPossible = false;
            break;
        }
        ny+=1;
        if(outOfRange(nx, ny) || wood[ny][nx]!=0){
            isPossible = false;
            break;
        }
    }
    if(isPossible) {
        cy+=1;
        cx+=1;
        dir+=1;
        if(dir>3) {
            dir=0;
        }
    }
    return pi(cx, cy);
}

bool outWoods(int x, int y) {
    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(outOfWoodRange(nx, ny)) {
            return false;
        }
    }
    return true;
}

pi moveBottom(int start) {
    pi horse = {start, 1}; // x, y

    while(true) {
        // 앞으로
        bool isPossible = false;
        pi moveHorse = moveSouth(horse);
        if(moveHorse.first!=horse.first || moveHorse.second != horse.second) {
            isPossible =true;
        }

        // 서쪽
        pi dirHorse = moveAndLeftSpin(moveHorse);

        // 안되면 동쪽
        if(moveHorse.first==dirHorse.first && moveHorse.second==dirHorse.second) {
            dirHorse = moveAndRightSpin(moveHorse);
        }
        if(dirHorse.first!=horse.first || dirHorse.second != horse.second) {
            isPossible =true;
        }
        horse = dirHorse;

        if(!isPossible) {
            if(!outWoods(horse.first, horse.second)) { // 정령 다 빠져나감
                wood.assign(r+1+2, vector<int>(c+1,0));
                movePossible = false;
                number = 1;
            }else {
                wood[horse.second][horse.first] = number;
                for(int i=0; i<4; i++) {
                    int cx = horse.first+dx[i];
                    int cy = horse.second+dy[i];
                    if(i==dir) {
                        wood[cy][cx] = -number;
                    }else {
                        wood[cy][cx] = number;
                    }
                }
                number++;
                movePossible=true;
            }
            break;
        }
    }
    return horse;
}

void moveAndCalcMax(pi horse) { // 정령이동
    int maxs = 0;

    vector<vector<bool>> visited(r+1+2, vector<bool>(c+1,false));
    queue<pi> que;
    que.push({horse.first, horse.second});
    visited[horse.second][horse.first] = true;
    maxs = max(maxs, horse.second);

    while(!que.empty()) {
        int cx = que.front().first;
        int cy = que.front().second;
        maxs = max(maxs, cy);
        que.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(outOfWoodRange(nx, ny) || visited[ny][nx] || wood[ny][nx]==0) {
                continue;
            }
            if(wood[cy][cx]>0 && abs(wood[ny][nx])== abs(wood[cy][cx])) {
                que.push({nx, ny});
                visited[ny][nx] = true;
            }
            if(wood[cy][cx]<0) {
                que.push({nx, ny});
                visited[ny][nx] = true;
            }


        }
    }

    row_total+=maxs-2;
}

int main() {
    cin >> r >> c >> k;

    wood.assign(r+1+2, vector<int>(c+1,0)); // 답에서는 r-2로 해주기

    for(int i=0; i<k; i++) {
        int start, direction;
        cin >> start >> direction;
        dir=direction;
        pi horseLocation = moveBottom(start);
        if(movePossible) {
            moveAndCalcMax(horseLocation);
        }
    }
    cout << row_total << '\n';
    return 0;
}