#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
vector<vector<int>> poTop;
vector<vector<int>> attackTime; // 최근에 공격한 시간

vector<vector<bool>> visited;
vector<vector<bool>> isAttack;
vector<vector<pi>> back;
int number =0;

int n, m;
int dx[] = {1,0,-1,0}; // 여기 우하좌상 실수
int dy[] = {0,1,0,-1};


bool cmpMin(pi a, pi b) {
    if(attackTime[a.second][a.first] == attackTime[b.second][b.first]) {
        if(a.second+a.first == b.second+b.first) {
            return a.first >b.first;
        }
        return a.second+a.first > b.second+b.first;
    }
    return attackTime[a.second][a.first] > attackTime[b.second][b.first];
}

bool cmpMax(pi a, pi b) {
    if(attackTime[a.second][a.first] == attackTime[b.second][b.first]) {
        if(a.second+a.first == b.second+b.first) {
            return a.first < b.first;
        }
        return a.second+a.first < b.second+b.first;
    }
    return attackTime[a.second][a.first] < attackTime[b.second][b.first];
}


pi setAttacker() {
    int min_num = 6000;
    vector<pi> mins;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(poTop[i][j] ==0)
                continue;
            min_num = min(min_num, poTop[i][j]);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(min_num == poTop[i][j]) {
                mins.push_back({j, i});
            }
        }
    }
    if(mins.size()>1) {
        sort(mins.begin(), mins.end(), cmpMin);
    }
    return mins[0];
}
pi findAttacked() {
    int max_num = 0;
    vector<pi> maxs;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(poTop[i][j] ==0)
                continue;
            max_num = max(max_num, poTop[i][j]);
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(max_num == poTop[i][j]) {
                maxs.push_back({j, i});
            }
        }
    }

    if(maxs.size()>1) {
        sort(maxs.begin(), maxs.end(), cmpMax);
    }
    return maxs[0];

}

bool attackStart(int x, int y, pi attackedLoc) {
    bool isPossible = false;

    back.assign(n, vector<pi>(m, {-1,-1}));
    queue<pi> que;
    que.push({x, y});
    while(!que.empty()) {

        int cx = que.front().first;
        int cy = que.front().second;
        que.pop();

        if(cx == attackedLoc.first && cy == attackedLoc.second){
            isPossible = true;
            break;
        }

        for(int i=0; i<4; i++) {
            int nx = (cx + dx[i] + m)%m;
            int ny = (cy + dy[i] + n)%n;
            if(visited[ny][nx] || poTop[ny][nx]==0) {
                continue;
            }

            visited[ny][nx] = true;
            back[ny][nx] = {cx,cy};
            que.push({nx,ny});
        }
    }

    return isPossible;

}
void laizerAttack(pi attackLoc, int x, int y, int score) {

    poTop[y][x] -= score;
    isAttack[y][x] = true;
    if(poTop[y][x]<=0){
        poTop[y][x] = 0;
        number--;
        if(number<2) {
            return;
        }
    }
    score /=2;

    while(1) {

        int nx = back[y][x].first;
        int ny = back[y][x].second;
        isAttack[ny][nx] = true;
        if(nx==attackLoc.first && ny ==attackLoc.second) {
            break;
        }
        if(poTop[ny][nx] <= score) {
            poTop[ny][nx] = 0;
            number--;
            if(number<2) {
                return;
            }
        } else {
            poTop[ny][nx] -= score;
        }
        x = nx; y = ny;
    }

}

void potanAttack(int x, int y, int score, pi attackLoc) {

    int ddx[] = {1,0,-1,0, 1,1,-1,-1};
    int ddy[] = {0,-1,0,1,1,-1,-1,1};
    poTop[y][x] -= score;
    isAttack[y][x] = true;
    if(poTop[y][x]<=0){
        poTop[y][x] = 0;
        number--;
        if(number<2) {
            return;
        }
    }
    score /=2;

    for(int i=0; i<8; i++) {
        int nx = (x + ddx[i] + m)%m; // 여기서 음수 나올 수 있는데 제대로 처리 안해서 오류
        int ny = (y + ddy[i] + n)%n;

        if(nx == attackLoc.first && ny == attackLoc.second) {
            continue;
        }
        if(poTop[ny][nx] == 0) {
            continue;
        }

        isAttack[ny][nx] = true;

        if(poTop[ny][nx]>score) {
            poTop[ny][nx] -= score;
        }else {
            poTop[ny][nx] =0;
            number--;
            if(number<2) {
                return;
            }
        }

    }
}

void plusScore() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!isAttack[i][j] && poTop[i][j]>0) {
                poTop[i][j]++;
            }
        }
    }
}
int main() {
    int k;
    cin>>n>>m>>k;
    poTop.assign(n, vector<int>(m,0));
    attackTime.assign(n, vector<int>(m, 0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>> poTop[i][j];
            if(poTop[i][j] >0) {
                number++;
            }
        }
    }

    for(int i=1; i<=k; i++) {
        if(number<2) {
            break;
        }
        // 1. 공격자 선정
        pi attackLoc = setAttacker();

        // 2. 공격
        pi attackedLoc = findAttacked(); // 공격자 선정

        poTop[attackLoc.second][attackLoc.first]+= (n+m);
        attackTime[attackLoc.second][attackLoc.first] = i;
        int score = poTop[attackLoc.second][attackLoc.first];

        // 경로 찾기

        visited.assign(n, vector<bool>(m, false));
        visited[attackLoc.second][attackLoc.first] = true;

        bool isPossible = attackStart(attackLoc.first, attackLoc.second, attackedLoc); // 공격 경로 찾기

        isAttack.assign(n,vector<bool>(m, false));
        isAttack[attackLoc.second][attackLoc.first] = true;
        isAttack[attackedLoc.second][attackedLoc.first] = true;

        if(!isPossible) {

            potanAttack(attackedLoc.first, attackedLoc.second, score, attackLoc);
        }else {
            laizerAttack(attackLoc, attackedLoc.first, attackedLoc.second, score);
        }

        // 3. 포탑 정비
        plusScore();


    }

    int max_num = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            max_num = max(max_num, poTop[i][j]);
        }
    }
    cout << max_num << '\n';
    return 0;
}