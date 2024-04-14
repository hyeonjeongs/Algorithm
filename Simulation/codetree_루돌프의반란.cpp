#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <algorithm>

#define DIE 1e4

using namespace std;
typedef pair<int, int> pi;
int n, m, p, c_num, d_num;
int rr, cc; // 루돌프 위치
vector<pi> santa;
vector<vector<int>> location;
vector<int> status;
vector<int> point;
int dr[] = {-1, 0,1,0, -1, -1, 1, 1}; // (상 우 하 좌) , (좌상 우상 우하 좌하)
int dc[] = {0,1,0,-1, -1, 1, 1,-1};
int m_num =0;
int total =0;
struct Rudol {
    int r;
    int c;
    int num;
    int dir;
};
bool cmp(Rudol a, Rudol b){
    if(a.num == b.num){
        if(a.r == b.r){
            return a.c > b.c;
        }
        return a.r > b.r;
    }
    return a.num < b.num;
}

bool cmpSanta(Rudol a, Rudol b) {
    if(a.num == b.num){
        return a.dir < b.dir;
    }
    return a.num < b.num;
}

void init() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n >>m >>p >> c_num >>d_num;
    cin>> rr >> cc;
    santa.assign(n+1, pi());
    status.assign(n+1, 0);
    point.assign(n+1, 0);
    location.assign(n+1, vector<int>(n+1, -1));
    location[rr][cc] = 0;
    total = p;

    for(int i=0; i<p; i++) {
        int index;
        cin>> index;
        cin>> santa[index].first >> santa[index].second;
        location[santa[index].first][santa[index].second] = index;
    }
}

int distance(int nr, int nc, int rs, int cs){
    return pow(nr-rs, 2) + pow(nc-cs, 2);
}

bool outOfBounds(int r, int c){
    return !(r>0 && r<=n && c>0 && c<=n);
}

void collapseRudolToSanta(int r, int c, int dir) {

    vector<Rudol> move_data;
    int index;
    // 루돌프가 -> 산타
    index = location[r][c]; // 산타 인덱스
    point[index] += c_num;
    status[index] = -m_num; // 해당 산타 기절

    // 새로운 산타 밀기
    int nr = r + dr[dir] *c_num;
    int nc = c + dc[dir] *c_num;
    if(outOfBounds(nr, nc)) {
        status[index] = DIE;
        total--;
        return;
    }
    move_data.push_back(Rudol({nr, nc, index, dir}));

    // 또 산타 있으면 계속 이동시켜야
    // 바로 기절시켜야함
    while(1) {
        if(location[nr][nc] <0)
            break;
        int before = location[nr][nc];
        nr += dr[dir];
        nc += dc[dir];

        if(outOfBounds(nr, nc)){
            status[location[nr][nc]] = DIE;
            total--;
            break;
        }
        move_data.push_back((Rudol({nr, nc, before, dir})));
    }

    // 전체적 바꾸기
    for(int i=0; i<move_data.size(); i++) { // 산타 위치와 배열 상태 바꾸기
        Rudol ru = move_data[i];
        location[ru.r][ru.c] = ru.num;
        santa[ru.num].first = ru.r;
        santa[ru.num].second = ru.c;
    }
}

void moveRudolpu() {
    int dis = 3000;
    vector<Rudol> min_dis;
    vector<int> clear;
    for(int i=0; i<8; i++) {
        int nr = rr + dr[i];
        int nc = cc + dc[i];
        if(outOfBounds(nr, nc)) continue;
        for(int j=1; j<=p; j++) {
            if(status[j]== DIE){ // 현재 죽은 상태면
                continue;
            }
            int current_dis = distance(nr, nc, santa[j].first, santa[j].second);
            if(dis>current_dis) {
                dis = current_dis;
                min_dis.push_back(Rudol({nr, nc, current_dis, i}));
            }
        }
    }
    sort(min_dis.begin(), min_dis.end(), cmp);
    location[rr][cc] = -1;
    rr = min_dis[0].r;
    cc = min_dis[0].c;
    if(location[rr][cc]>0) { // 산타 있으면 충돌
        // 충돌
        collapseRudolToSanta(rr, cc, min_dis[0].dir);
    }
    location[rr][cc] = 0; // 루돌프 영역으로 하기
}

void collapseSantaToRudol(int index, int r, int c, int dir) {
    vector<Rudol> move_data;
    point[index] += d_num;
    int back_dir = (dir+2)%4;
    int nr = r + dr[back_dir];
    int nc = c + dc[back_dir];
    move_data.push_back(Rudol({nr, nc, index, back_dir}));

    while(1) {
        if(location[nr][nc]<1) break;
        // 새로운 자리에 옮길놈
        index = location[nr][nc];
        nr += dr[back_dir];
        nc += dc[back_dir];

        if(outOfBounds(nr, nc)){
            status[index] = DIE;
            total--;
            break;
        }
        if(location[nr][nc]>0){
            break;
        }
        move_data.push_back({nr, nc, index, back_dir});
    }

    // 전체적 바꾸기
    for(int i=0; i<move_data.size(); i++) { // 산타위치와 배열 상태 바꾸기
        Rudol ru = move_data[i];
        location[ru.r][ru.c] = ru.num;
        santa[ru.num].first = ru.r;
        santa[ru.num].second = ru.c;
    }

}
void moveSanta() {
    for(int i=1; i<=p; i++) { // 현재 index
        if(status[i] != 0){ // 죽었거나 잠궈있으면
            continue;
        }
        vector<Rudol> ru;
        int current_dis = distance(santa[i].first, santa[i].second, rr, cc);
        for(int j=0; j<4; j++) {
            int nr = santa[i].first + dr[i];
            int nc = santa[i].second + dc[i];

            if(outOfBounds(nr, nc) || location[nr][nc]>0) {
                continue;
            }

            int dis = distance(nr, nc, rr, cc);
            if(dis <= current_dis){ // 이거 같은거 맞는지 !!!!
                ru.push_back(Rudol({nr, nc, dis, j}));
            }
        }

        // 움직이기
        // 루돌프 충돌
       if(ru.size()==0) return;

        sort(ru.begin(), ru.end(), cmpSanta);
        if(location[ru[0].r][ru[0].c] ==0){
            status[i] = -(status[i]);
            collapseSantaToRudol(i, ru[0].r, ru[0].c, ru[0].dir);
        } else{
            location[santa[i].first][santa[i].second] = -1;
            santa[i].first = ru[0].r;
            santa[i].second = ru[0].c;
            location[ru[0].r][ru[0].c] = i;
        }

    }
}

int main() {

    init();

    for(int i=1; i <=m; i++) {
        // 잠근거 풀건지
        for(int k=1; k<=p; k++) {
            if(status[i] <0) {
                if(i-status[i]==2){
                    status[i] = -(status[i]);
                }
            }
        }
        // 루돌프 움직임
        m_num = i;
        moveRudolpu();

        // 산타 움직임 -> 충돌
        moveSanta();

        for(int j=1; j<=p; j++) {
            if(status[j]== DIE) continue;
            point[j]++;
        }
        if(total <=0) break;

    }

    for(int i=1; i<=p; i++) {
        cout<< point[i] << " ";
    }


    return 0;
}