#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct LOCATION {
    int x;
    int y;
    int dir; // 방향 (위, 오른쪽, 아래, 왼쪽)
};

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
vector<vector<bool>> tree_exist;

vector<LOCATION> runner;
LOCATION attacker;
int n, m, h, k;

int change = 1; // 이동 숫자
int counts = 0; // 2 할때마다 change 바뀜
int current_count = 0; // 현재 몇번 갔는지
bool is_front = true;

bool outOfRange(int x, int y) {
    if(x <=0 || x>n || y<=0 || y>n) {
        return true;
    }
    return false;
}

int distDiff(int x1, int y1, int x2, int y2) {
    return abs(x1- x2) + abs(y1- y2);
}

void moveRunner() {
    for(int i=0; i<runner.size(); i++) {
        if(runner[i].dir<0) { // 음수면 사라진 것
            continue;
        }
        int ndir = runner[i].dir;
        int cx = runner[i].x;
        int cy = runner[i].y;

        if(distDiff(cx, cy, attacker.x, attacker.y) > 3) {
            continue;
        }

        int nx = cx + dx[ndir];
        int ny = cy + dy[ndir];

        if(outOfRange(nx, ny)) { // 범위 벗어나면 방향 바꿔주기
            ndir = (ndir + 2) % 4;
            nx = cx + dx[ndir];
            ny = cy + dy[ndir];
        }

        if(nx == attacker.x && ny == attacker.y) { // 공격자랑 같은 칸이면 움직이지 않기
            runner[i].dir = ndir;
            continue;
        }
        runner[i] = {nx, ny, ndir};

    }

}

void moveAttacker() {

    current_count++;

    int cx = attacker.x;
    int cy = attacker.y;
    int dir = attacker.dir;

    int nx = cx + dx[dir];
    int ny = cy + dy[dir];

    if(current_count == change) {
        dir = (dir+1)%4;
        counts++;
        current_count = 0;
    }

    if(counts == 2) {
        change++;
        counts = 0;
        current_count=0;
    }

    attacker = {nx, ny, dir};
}

void moveBackAttacker() {
    int cx = attacker.x;
    int cy = attacker.y;
    int dir = attacker.dir;

    current_count++;

    int nx = cx + dx[dir];
    int ny = cy + dy[dir];

    if(current_count == change) {
        dir = (dir - 1 + 4)%4;
        counts++;
        current_count=0;
    }

    if(counts == 2) {
        change--;
        counts = 0;
        current_count=0;
    }

    attacker = {nx, ny, dir};
}

int catchRunner() {
    int cx = attacker.x;
    int cy = attacker.y;
    int dir = attacker.dir;
    int result = 0;

    for(int i=0; i<3; i++) { // 현재 방향으로 3만큼만 잡을 수 있음
        for(int j=0; j<runner.size(); j++) {

            if(tree_exist[runner[j].y][runner[j].x] || runner[j].dir == -1) {
                continue;
            }
            if(runner[j].x == cx && runner[j].y == cy) {
                result++;
                runner[j].dir = -1; // 없애는 것
            }
        }
        cx += dx[dir];
        cy += dy[dir];
    }

    return result;
}

int main() {
    int result = 0;
    cin >> n>> m >> h >> k;
    tree_exist.assign(n+1, vector<bool>(n+1, false));
    attacker={n/2+1, n/2+1, 0};

    for(int i=0; i<m; i++) {
        int x, y, d;
        cin >> y >> x >> d;
        runner.push_back({x, y, d});
    }

    for(int i=0; i<h; i++) {
        int x, y;
        cin >> y >> x;
        tree_exist[y][x] = true;
    }
    // k번의 턴
    for(int i=1; i<=k; i++) {
        // 도망자 다 움직이기
        moveRunner();

        // 공격자 움직이기
        if(is_front){
            moveAttacker();
        }else {
            moveBackAttacker();
        }
        if(attacker.x ==1 && attacker.y == 1) {
            is_front = false;
            current_count = 0;
            change = n-1;
            counts = -1; // 틀린 이유 : 이 부분 체크 못함 (마지막 부분은 3번 가야함)
            attacker.dir = 2;
        }
        if(attacker.x == n/2+1 && attacker.y == n/2+1) {
            is_front = true;
            current_count = 0;
            change = 1;
            counts = 0;
            attacker.dir = 0;
        }

        // 술래가 방향내 도망자 잡음
        int answer = catchRunner() * i;
        result += answer;

    }
    cout << result << '\n';

    return 0;
}