#include <iostream>
#include <vector>
#include <queue>
#define MAX_CHESS 40

using namespace std;
typedef pair<int,int> pi;
vector<vector<int>> chess;
vector<vector<int>> chess_person; // 기사들 표시
vector<vector<pi>> people; // i번 기사의 좌표들
vector<int> energy; // i 번 기사의 에너지
int l, n, q;
int dr[] = {1,0,-1,0}; // 위, 오른쪽, 아래, 왼쪽
int dc[] = {0,1,0,-1};


void init() {
    cin>>l>>n>>q;
    chess.assign(l+2,vector<int>(l+2,2));
    people.assign(n+1, vector<pi>()); // 1번부터 기사들 인덱스
    chess_person.assign(l+2, vector<int>(l+2, 0));
    energy.assign(n+1, 0);

    for(int i=1; i<=l; i++) {
        for(int j=1; j<=l; j++){
            cin>> chess[i][j];
        }
    }


    for(int i=1; i<=n; i++) { // i가 i번째 기사
        int r, c, h, w, k;
        cin>> r>> c >> h >> w >> k;
        energy[i] = k;

        for(int u=0; u<h; u++) {
            for(int m=0; m<w; m++) {
                int nr = r+ u;
                int nc = c+ m;
                people[i].push_back({nr, nc});
                chess_person[nr][nc] = i;

            }
        }
    }


}
void removePerson(int index) {
    for(int i=0; i<people[index].size(); i++) {
        pi data = people[index][i];
        chess_person[data.first][data.second] = 0;
    }
}
void goPeople(int index, int d) {
    // 이동 (벽 있으면 못 움직임)
    // 이동할 애들 찾기
    vector<int> visited(n+1, false);
    queue<int> que;
    vector<int> attack_person;

    que.push(index);
    visited[index] = true;
    attack_person.push_back(index);
    bool current = true;

    while(!que.empty()) {
        int idx = que.front();
        que.pop();
        for(int i=0; i<people[idx].size(); i++) {
            int nr = people[idx][i].first + dr[d];
            int nc = people[idx][i].second + dc[d];
            if(chess[nr][nc] == 2) {
                current = false;
                break;
            }
            if(visited[chess_person[nr][nc]]) continue;

            if(chess_person[nr][nc]!=idx && chess_person[nr][nc]>0 && energy[chess_person[nr][nc]]>0) { // 밀어야 할 기사들
                que.push(chess_person[nr][nc]);
                visited[chess_person[nr][nc]] = true;
                attack_person.push_back(chess_person[nr][nc]);
            }

        }
        if(!current) break;
    }

    if(!current) // 큐가 비어 있지 않으면 못 움직이는 것
        return;

    for(int i=0; i<attack_person.size(); i++) {
        int idx= attack_person[i];
        for(int j=0; j<people[idx].size(); j++) {
            int cr = people[idx][j].first;
            int cc = people[idx][j].second;
            int nr = people[idx][j].first +dr[d];
            int nc = people[idx][j].second +dc[d];

            if(chess_person[cr][cc] == idx){ // 투입 안된경우
                chess_person[cr][cc] = 0;
            }

            chess_person[nr][nc] = idx;

            people[idx][j].first = nr;
            people[idx][j].second = nc;
        }
    }

    // 영역 check (데미지 감소)
    // 명령 받은애는 데미지 안 받음
    cout<< attack_person.size() << " skf "<<endl;
    for(int i=1; i<attack_person.size(); i++) {
        int idx = attack_person[i];
        for(int j=0; j< people[idx].size(); j++) {
            int cr = people[idx][j].first;
            int cc = people[idx][j].second;
            if(chess[cr][cc] ==1){
                if(energy[idx]<=0) {
                    continue;
                }
                energy[idx]--;
                if(energy[idx] ==0) {
                    removePerson(idx);
                }
            }
        }
    }
}

int main() {

    init();
    vector<int> origin_energy = energy;

    // q번의 대결
    for(int j=0; j<q; j++) {
        int i, d;
        cin>> i>>d;
        if(energy[i] <=0) continue;
        goPeople(i, d);
    }

    int result = 0;
    for(int i=1; i<=n; i++) {
        if(energy[i] >0){
            result += (origin_energy[i] - energy[i]);
        }
    }

    cout<< result;
    return 0;
}