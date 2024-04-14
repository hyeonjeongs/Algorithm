#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, k;
int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};
struct Person{
    int r;
    int c;
    int d;
    int energy;
    int gun;
};

vector<vector<priority_queue<int>>> floors; // 총의 위치
vector<Person> people; // 플레이어 정보
vector<vector<int>> people_idx; //플레이어 인덱스에표시
vector<int> points;

void init() {
    floors.assign(n+1, vector<priority_queue<int>>(n+1));
    people_idx.assign(n+1, vector<int>(n+1,-1));
    points.assign(m,0);

    // 총 넣기
    for(int i=1; i<=n; i++){ // 0일때도 넣어야하는지 확인
        for(int j=1; j<=n; j++) {
            int input;
            cin>>input;
            floors[i][j].push(input);
        }
    }
    // 사람들 정보 입력
    for(int i=0; i<m; i++) {
        Person person;
        cin>> person.r >> person.c >> person.d >> person.energy;
        person.gun=0;
        people.push_back(person);
        people_idx[person.r][person.c] = i;
    }



}
bool outOfBound(int r, int c) {
    return !(r>=1 && r<=n && c>=1 && c<=n);
}
void changeGun(int index, int fr, int fc) {
    // 총 가져가
    int gun_energy = people[index].gun;
    int floor_energy = floors[fr][fc].top();
    if(gun_energy >= floor_energy) { // 안바꿔도 됨
        return;
    }
    floors[fr][fc].pop();
    people[index].gun = floor_energy;
    floors[fr][fc].push(gun_energy);

}

void playGame(){


    // 방향으로 이동 (격자 벗어나는 경우 체크)
    //플에이어 있니 -> 총있니
    for(int i=0; i<m; i++) { // i가 플레이어의 인덱스

        Person p1 = people[i];
        int nr = p1.r + dr[p1.d];
        int nc = p1.c + dc[p1.d];
        // 격자벗어나면 정반대 방향
        if(outOfBound(nr, nc)) {
            nr = p1.r + dr[(p1.d+2)%4];
            nc = p1.c + dc[(p1.d+2)%4];
            people[i].d = (p1.d+2)%4; // 방향 바꿔줘야함
        }
        people_idx[p1.r][p1.c] = -1;

        if(people_idx[nr][nc]>-1) { //플레이어 있는 경우
            int win=-1, lose=-1;
            // 싸우기
            Person p2 = people[people_idx[nr][nc]]; // 원래 있던애
            int p1_energy = p1.energy + p1.gun;
            int p2_energy = p2.energy + p2.gun;
            if(p1_energy > p2_energy) {
                win = i;
                lose = people_idx[nr][nc];
            }else if(p1_energy < p2_energy) {
                lose = i;
                win = people_idx[nr][nc];
            } else { // 같으면
                if(p1.energy >p2.energy){
                    win = i;
                    lose = people_idx[nr][nc];
                }else {
                    lose = i;
                    win = people_idx[nr][nc];
                }
            }
            // 이긴 놈 (포인트 얻고, 총 교체, 좌표 교체)
            points[win] += people[win].energy+people[win].gun - (people[lose].energy + people[lose].gun);

            // 진 놈(움직이기, 거기서 총교체)
            // 총 내려놓기 (없을수도)
            // 사람 있으면 90도 회전 -> 이동
            if(people[lose].gun>0) { // 진애는 총 내려놓기
                floors[nr][nc].push(people[lose].gun);
                people[lose].gun = 0;
            }
            int move_direction = people[lose].d;
            int lr,lc;
            for(int b=0; b<4; b++) { // 방향에 따라 이동
                lr = nr + dr[(move_direction+b)%4];
                lc = nc + dc[(move_direction+b)%4];
                if(outOfBound(lr, lc) || people_idx[lr][lc]>-1){ // 방향 바꿔쥐기
                    continue;
                } else {
                    changeGun(lose, lr, lc);
                    people[lose].d = (move_direction+b)%4;
                    break;
                }
            }
            changeGun(win, nr, nc); // 여기를 진애가 떨어뜨린 총까지 계산 안해서 틀렸었음 (문제 잘 읽자...)
            // 위치 바꼈으면 people_idx, people 위치 갱신
            people_idx[nr][nc] = win;
            people_idx[lr][lc] = lose;
            people[win].r = nr; people[win].c = nc;
            people[lose].r = lr; people[lose].c = lc;

        } else {
            // 플레이어 x, 총확인
            changeGun(i, nr, nc);
            people_idx[nr][nc] = i;
            people[i].r = nr; people[i].c = nc;
        }

    }
}

int main() {
    cin>>n>>m>>k;

    init();

    for(int i=0; i<k; i++) {
        // 플레이어 수만큼 이동, fight
        playGame();
    }

    for(int i=0;i <m; i++) {
        cout<< points[i] << " ";
    }

    return 0;
}