#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct DATA {
    int x;
    int y;
};
struct MOVE {
    int x;
    int y;
    int dir;
};
int n, m;
int cnt = 0;
vector<vector<int>> location;
vector<DATA> people;
vector<DATA> store;
vector<bool> is_possible;
int dx[] = {0,-1,1,0};
int dy[] = {-1,0,0,1};

bool cmp(DATA a, DATA b) {
    if(a.y== b.y) {
        return a.x < a.y;
    }
    return a.y < b.y;
}
bool outOfRange(int x, int y) {
    if(x<=0 || y<=0 || x>n || y>n) {
        return true;
    }
    return false;
}

DATA findNearStore(int x, int y, DATA goal) { // 가까운 편의점 방향으로 이동

    queue<MOVE> que;
    vector<vector<bool>> isvisited(n+1, vector<bool>(n+1, false));
    que.push({x, y, 0});
    isvisited[y][x] = true;
    int count = -1;

    while(!que.empty()) {
        int cx = que.front().x;
        int cy = que.front().y;
        int dir = que.front().dir;
        que.pop();

        if(cx == goal.x && cy == goal.y) {
            return DATA({x+dx[dir], y+dy[dir]});
        }

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(outOfRange(nx, ny) || isvisited[ny][nx] || location[ny][nx]<0) {
                continue;
            }
            if(count == -1){
                dir = i;
            }
            que.push({nx, ny, dir});
            isvisited[ny][nx] = true;
        }
        count=0;
    }
    return DATA({0,0});
}

DATA findNearBaseCamp(DATA start) { // 편의점과 가까운 베이스캠프로 이동

    queue<MOVE> que;
    vector<vector<bool>> isvisited(n+1, vector<bool>(n+1, false));
    int min_dist = n*n +1;
    vector<DATA> candidate;

    que.push({start.x, start.y, 0});
    isvisited[start.y][start.x] = true;

    while(!que.empty()) {
        int cx = que.front().x;
        int cy = que.front().y;
        int dir = que.front().dir;
        que.pop();

        if(location[cy][cx] == 1) { // 베이스 캠프 도착
            if(min_dist>=dir) {
                min_dist = dir;
                candidate.push_back({cx, cy});
            }
        }

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(outOfRange(nx, ny) || isvisited[ny][nx] || location[ny][nx]<0) {
                continue;
            }
            que.push({nx, ny, dir+1});
            isvisited[ny][nx] = true;
        }
    }
    if(candidate.size()<=0) {
        candidate.push_back({0,0});
    }
    sort(candidate.begin(), candidate.end(), cmp);

    return candidate[0];
}

void movePeople() {
    for(int i=1; i<=people.size(); i++) {
        if(!is_possible[i] || people[i].x == 0) { // 도착했거나 입장안하면 안움직임
            continue;
        }
        DATA move_location = findNearStore(people[i].x, people[i].y, store[i]);
        people[i].x = move_location.x;
        people[i].y = move_location.y;

        // 만약 편의점 도착이면 is_possible false로
        if(people[i].x == store[i].x && people[i].y == store[i].y) {
            is_possible[i] = false;
            location[move_location.y][move_location.x] = -2;
            cnt++;
        }

    }
}

void entrancePeople(int time) {
    DATA start = store[time];

    DATA move_location = findNearBaseCamp(start);
    people[time].x = move_location.x;
    people[time].y = move_location.y;

    location[move_location.y][move_location.x] = -1; // 베이스 캠프 이제 지날 수 없음
}

int main() {

    cin>> n>> m;
    location.assign(n+1, vector<int>(n+1, 0));
    is_possible.assign(m+1, true);
    people.assign(m+1, DATA({0,0}));
    store.assign(m+1, DATA({0,0}));

    for(int i=1; i<=n; i++) { // 베이스 캠프 위치
        for(int j=1; j<=n; j++) {
            cin >> location[i][j];
        }
    }
    for(int i=1; i<=m; i++) { // 편의점 위치 입력받기
        int x, y;
        cin >> y >> x;
        store[i] = {x, y};
        location[y][x] = 2;
    }

    int time = 0;
    while(1){
        if(cnt>=m) {
            break;
        }
        time++;

        // 격자 내 사람들 이동
        movePeople();

        // t번 베이스 캠프로 입장 (t<=m 이면)
        if(time<=m) {
            entrancePeople(time);
        }
    }
    cout << time<< '\n';

    return 0;
}