#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
typedef pair<int, int> pi;
int dx[] = {0,0,-1,1}; //상하좌우
int dy[] = {-1,1,0,0};

int ddx[] = {-1,1,0,0}; //상하좌우
int ddy[] = {-1,1,-1,1};

struct PERSON {
    int x;
    int y;
    int possible; // -1,0, 1
};

int n, m;
int move_result=0, stone_num=0, attack_num=0;

vector<int> people_loc[50][50];
vector<vector<int>> city;
pi house;// x, y
pi park;// x, y
vector<vector<bool>> sight; // 메두사 보는곳 갱신
vector<PERSON> people; // 전사들 정보
vector<pi> medu_moves;  // 메두사 최단경로
int medu_move_index = 0; // 메두사 최단경로 인덱스

bool outOfRange(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= n;
}

int minDist(int x1, int x2, int y1, int y2) { //멘헨튼 거리 구하기
    return abs(x1-x2) + abs(y1-y2);
}

struct MEDU {
    int x;
    int y;
    vector<pi> location;
};
void findMinMeduDist() { // 메두사 집까지의 최단경로 찾기

    queue<MEDU> que;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    que.push({house.first, house.second, vector<pi>(1, {house.first, house.second})});  // x, y
    visited[que.front().y][que.front().x] = true;

    while(!que.empty()) {
        int cx = que.front().x;
        int cy = que.front().y;
        vector<pi> loc = que.front().location;
        que.pop();

        if(cx == park.first && cy == park.second) {
            medu_moves = loc;
            return;
        }

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(outOfRange(nx, ny) || visited[ny][nx] || city[ny][nx] == 1) {
                continue;
            }
            visited[ny][nx] = true;
            vector<pi> next_loc = loc;
            next_loc.push_back({nx, ny});

            que.push({nx, ny, next_loc});
        }
    }
}

void moveMedu() {
    house = medu_moves[++medu_move_index];

    int x = house.first;
    int y = house.second;

    if(people_loc[y][x].size()>0) {
        for(int i=0; i<people_loc[y][x].size(); i++) {
            people[people_loc[y][x][i]].possible = -1;
        }
    }
    vector<int> reset;
    people_loc[y][x] = reset;

}

void spread(int r, int c) {

}

void spreadSight() {

    vector<vector<bool>> result_sight; // 최종적으로 저장할 전사 위치
    vector<pi> result_catch_index;
    queue<pi> que;
    int x = house.first;
    int y = house.second;

    for(int i=0; i<4; i++) {
        vector<pi> catch_index; // 병사정보들 (잡힌놈들 -> 나중에 처리해야함)
        vector<bool> see_index(n, false); // 보인놈들 i나 j 인덱스 표시해서 다른병사들 안보이는거 표시
        vector<vector<bool>> sight_copy(n, vector<bool>(n, false)); // 퍼지는거 저장

        vector<pi> catch_people_index;
        int pluses[] = {-1,0,1};

        if(i==0) { // 위
            if(y==0) {
                continue;
            }
            que.push({x-1, y-1});
            que.push({x, y-1});
            que.push({x+1, y-1});

            while(!que.empty()) {
                int cx = que.front().first;
                int cy = que.front().second;
                que.pop();
                sight_copy[cy][cx] = true;

                if(!see_index[cx] && people_loc[cy][cx].size()>0) {
                    catch_index.push_back({cx, cy});
                    see_index[cx] = true;
                }
                for(int j=0; j<3; j++) {
                    int nx = cx + pluses[j];
                    int ny = cy -1;
                    if(outOfRange(nx, ny) || sight_copy[ny][nx]) {
                        continue;
                    }
                    que.push({nx, ny});
                    sight[ny][nx] = true;
                }
            }
            if(catch_index.size()>result_catch_index.size()) { // 전사 개수 많은걸로
                result_catch_index = catch_index;
                result_sight = sight_copy;
            }
        } else if (i==1) { // 아래

            if(y==n-1) {
                continue;
            }
            que.push({x-1, y+1});
            que.push({x, y+1});
            que.push({x+1, y+1});

            while(!que.empty()) {
                int cx = que.front().first;
                int cy = que.front().second;
                que.pop();
                sight_copy[cy][cx] = true;

                if(!see_index[cx] && people_loc[cy][cx].size()>0) {
                    catch_index.push_back({cx, cy});
                    see_index[cx] = true;
                }
                for(int j=0; j<3; j++) {
                    int nx = cx + pluses[j];
                    int ny = cy +1;
                    if(outOfRange(nx, ny) || sight_copy[ny][nx]) {
                        continue;
                    }
                    que.push({nx, ny});
                    sight[ny][nx] = true;
                }
            }
            if(catch_index.size()>result_catch_index.size()) {
                result_catch_index = catch_index;
                result_sight =  sight_copy;
            }

        } else if (i==2) { // 왼
            if(x==0) {
                continue;
            }
            que.push({x-1, y-1});
            que.push({x-1, y});
            que.push({x+1, y+1});

            while(!que.empty()) {
                int cx = que.front().first;
                int cy = que.front().second;
                que.pop();
                sight_copy[cy][cx] = true;

                if(!see_index[cy] && people_loc[cy][cx].size()>0) {
                    catch_index.push_back({cx, cy});
                    see_index[cy] = true;
                }
                for(int j=0; j<3; j++) {
                    int nx = cx -1;
                    int ny = cy + pluses[j];
                    if(outOfRange(nx, ny) || sight_copy[ny][nx]) {
                        continue;
                    }
                    que.push({nx, ny});
                    sight[ny][nx] = true;
                }
            }
            if(catch_index.size()>result_catch_index.size()) {
                result_catch_index = catch_index;
                result_sight =  sight_copy;
            }

        } else { // 오

            if(x==n-1) {
                continue;
            }
            que.push({x+1, y-1});
            que.push({x+1, y});
            que.push({x+1, y+1});

            while(!que.empty()) {
                int cx = que.front().first;
                int cy = que.front().second;
                que.pop();
                sight_copy[cy][cx] = true;

                if(!see_index[cy] && people_loc[cy][cx].size()>0) {
                    catch_index.push_back({cx, cy});
                    see_index[cy] = true;
                }
                for(int j=0; j<3; j++) {
                    int nx = cx +1;
                    int ny = cy + pluses[j];
                    if(outOfRange(nx, ny) || sight_copy[ny][nx]) {
                        continue;
                    }
                    que.push({nx, ny});
                    sight[ny][nx] = true;
                }
            }
            if(catch_index.size()>result_catch_index.size()) {
                result_catch_index = catch_index;
                result_sight =  sight_copy;
            }

        }
    }

    sight = result_sight; // 매두사 시야 갱신

    for(int i=0; i<result_catch_index.size(); i++) {
        int xx = result_catch_index[i].first;
        int yy = result_catch_index[i].second;

        for(int j=0; j<people_loc[yy][xx].size(); j++) { // 돌로 만들기 (0)
            int people_index = people_loc[yy][xx][j];
            people[people_index].possible = 0;
            stone_num++;
        }
    }

}

void movePeople() {
    int total_move = 0;
    int attack_number = 0;

    // 첫번째 움직임
    for(int i=0; i<people.size(); i++) {
        int min_dist = 1e6;
        pi dist_loc;
        int x = people[i].x;
        int y = people[i].y;

        if(people[i].possible == 1) { // 이동가능하면
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(outOfRange(nx, ny) || sight[ny][nx]) {
                    continue;
                }
                int current_dist = minDist(x, nx, y, ny);
                if(current_dist<min_dist) {
                    dist_loc = {nx, ny};
                    min_dist = current_dist;
                }
            }
            if(min_dist!=1e6) {
                total_move+= minDist(x, dist_loc.first, y, dist_loc.second); // 총 움직인 거리 플러스하기
            }

            for(int j=0; j<people_loc[y][x].size(); j++){ // 이동시키기
                if(people_loc[y][x][j] == i) { // 해당하는내용 제거하기
                    people_loc[y][x].erase(people_loc[y][x].begin()+j);
                    break;
                }
            }
            if(dist_loc.first == house.first && dist_loc.second == house.second) {
                attack_number++;
                people[i].possible = -1;
            } else {
                people[i] = {dist_loc.first, dist_loc.second, 1};
                people_loc[dist_loc.second][dist_loc.first].push_back(i);
            }
        }
    }


    // 두번째 움직임
    for(int i=0; i<people.size(); i++) {
        int min_dist = 1e6;
        pi dist_loc;
        int x = people[i].x;
        int y = people[i].y;

        if(people[i].possible == 1) { // 이동가능하면
            for (int j = 0; j < 4; j++) {
                int nx = x + ddx[i];
                int ny = y + ddy[i];
                if(outOfRange(nx, ny) ||  sight[ny][nx]) {
                    continue;
                }
                int current_dist = minDist(x, nx, y, ny);
                if(current_dist<min_dist) {
                    dist_loc = {nx, ny};
                    min_dist = current_dist;
                }
            }
            if(min_dist!=1e6) {
                total_move+= minDist(x, dist_loc.first, y, dist_loc.second); // 총 움직인 거리 플러스하기
            }

            // 이동시키기
            for(int j=0; j<people_loc[y][x].size(); j++){ // 이동시키기
                if(people_loc[y][x][j] == i) { // 해당하는내용 제거하기
                    people_loc[y][x].erase(people_loc[y][x].begin()+j);
                    break;
                }
            }
            if(dist_loc.first == house.first && dist_loc.second == house.second) {
                attack_number++;
                people[i].possible = -1;
            } else {
                people[i] = {dist_loc.first, dist_loc.second, 1};
                people_loc[dist_loc.second][dist_loc.first].push_back(i);
            }
        }
    }
    move_result += total_move;
    attack_num = attack_number;

}
void changePossible() {
    for(int i=0; i<people.size(); i++) {
        if(people[i].possible == 0) {
            people[i].possible =1;
        }
    }
}

int main() {

    cin >> n >> m;
    cin >> house.second >> house.first >> park.second >> park.first;
    city.assign(n, vector<int>(n,0));
    sight.assign(n, vector<bool>(n,false));

    for(int i=0; i<m; i++) {
        int r, c;
        cin >> r >> c;

        people_loc[r][c].push_back(people.size());
        people.push_back({c, r, 1});
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> city[i][j];
        }
    }

    findMinMeduDist(); // 메두사 공원까지 최단거리 구하기
    if(medu_moves.size()<=0) {
        cout << "-1" << endl;
        return 0;
    }

    while(1) {
        moveMedu();
        if(house.first == park.first && house.second == park.second) {
            cout << "0"<< '\n';
            break;
        }
        // 초기화 (결과 출력값들)
        move_result=0, stone_num=0, attack_num=0;
        sight.assign(n, vector<bool>(n,false));

        spreadSight();
        movePeople();
        changePossible();
        cout << move_result << " " << stone_num << " "<< attack_num << '\n';
    }

    return 0;
}