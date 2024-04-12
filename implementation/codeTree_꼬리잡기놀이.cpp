#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;

struct Team{
    int r;
    int c;
    int num;
};
int n, m, k ;
vector<vector<bool>> visited;
vector<Team> teams;
vector<vector<int>> lines;

int dc[] = {1,0,-1,0};
int dr[] = {0,1,0,-1};
int final = 0;

void findTeam(int r, int c, int cnt) {
    queue<pi> que;
    que.push({r,c});

    int num=0;
    while(!que.empty()) {
        int cr = que.front().first;
        int cc = que.front().second;
        visited[cr][cc] = true;
        if(lines[cr][cc]==4) {
            lines[cr][cc] = cnt+5;
        }
        if(lines[cr][cc]==1) { // 방향 찾기
            num++;
            for(int j=0; j<4; j++) {
                int fr = cr + dr[j];
                int fc = cc + dc[j];
                if(lines[fr][fc] ==4){
                    teams.push_back({cr, cc, 0});
                    break;
                }
            }
        }
        if(lines[cr][cc] ==2 || lines[cr][cc]==3) {
            num++;
        }
        for(int i=0; i<4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if(nr<0 || nr>=n || nc <0 || nc>=n || visited[nr][nc] || lines[nr][nc]==0) {
                continue;
            }
            que.push({nr, nc});
        }
        que.pop();
    }
    teams[cnt].num = num; // 총 몇명인지 저장
}

vector<int> findOne(int r, int c) {
    queue<pi> que;
    vector<int> answer(4, 0);
    que.push({r,c});
    visited.assign(n, vector<bool>(n,false));
    int num =1;
    while(!que.empty()) {
        int cr = que.front().first;
        int cc = que.front().second;
        visited[cr][cc] = true;
        for(int i=0; i<4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr<0 || nr>=n || nc <0 || nc>=n || lines[nr][nc] <1 || visited[nr][nc]) {
                continue;
            }
            if(lines[nr][nc]>1 && lines[nr][nc] <4) {
                que.push({nr,nc});
                if(lines[nr][nc]==3) {
                    answer[2] = nr;
                    answer[3] = nc;
                }
            }
            if(lines[nr][nc] ==1) {
                answer[0] = num; // 총수
            }
            if(lines[nr][nc] >4) {
                answer[1] = lines[nr][nc];
            }
        }
        num++;
        que.pop();
    }

    return answer;
}

void moveRight(int index) {

    for(int i=0; i<n; i++) {
        if(lines[index][i]>0) {
            // 1을 찾으러가기
            vector<int> result = findOne(index, i);
            final += result[0]*result[0];
            // 1,2,3 아닌숫자 찾기
            teams[result[1]-5].r = result[2];
            teams[result[1]-5].c = result[3];
            break;
        }
    }
}

void moveUp(int index) {
    for(int i=n-1; i>0; i--) {
        if(lines[i][index]>0) {
            // 1을 찾으러가기
            vector<int> result = findOne(i, index);
            final += result[0]*result[0];
            // 1,2,3 아닌숫자 찾기
            teams[result[1]-5].r = result[2];
            teams[result[1]-5].c = result[3];
            break;
        }
    }
}
void moveLeft(int index) {
    for(int i=n-1; i>0; i--) {
        if(lines[index][i]>0) {
            // 1을 찾으러가기
            vector<int> result = findOne(index, i);
            final += result[0]*result[0];
            // 1,2,3 아닌숫자 찾기
            teams[result[1]-5].r = result[2];
            teams[result[1]-5].c = result[3];
            break;
        }
    }
}
void moveBottom(int index) {
    for(int i=0; i<n; i++) {
        if(lines[i][index]>0) {
            // 1을 찾으러가기
            vector<int> result = findOne(i, index);
            final += result[0]*result[0];
            // 1,2,3 아닌숫자 찾기
            teams[result[1]-5].r = result[2];
            teams[result[1]-5].c = result[3];
            break;
        }
    }
}

int main() {
    cin>>n>>m>>k;
    lines.assign(n, vector<int>(n,0));
    visited.assign(n, vector<bool>(n,false));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> lines[i][j];
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(lines[i][j] >0 && lines[i][j] <5 && !visited[i][j]) {
                findTeam(i, j, cnt);
                cnt++;
                if(cnt==m) break;
            }
        }
    }

    // 라운드 시작
    int dir = 0;

    for(int i=0; i<k; i++) {
        // 움직이기
        for(int j=0; j<m; j++) {
            queue<pi> que;
            int num_cnt = 1;
            int max_num = teams[j].num;
            que.push({teams[j].r,teams[j].c});
            while(!que.empty()) {
                if(max_num <= num_cnt) {
                    break;
                }
                int cr = que.front().first;
                int cc = que.front().second;
                int current_num = lines[cr][cc];
                for(int k=0; k<4; j++) {
                    int nr = cr + dr[k];
                    int nc = cc + dc[k];
                    if(nr<0 || nr>=n || nc <0 || nc>=n || lines[nr][nc]==0 || lines[nr][nc] == current_num) {
                        if(lines[nr][nc]<1 && lines[nr][nc]>3) {
                            continue;
                        }
                    }
                    if(lines[nr][nc]>4) { // 저장
                        lines[nr][nc] = lines[cr][cc];
                        lines[cr][cc] = 5+j;
                        if(num_cnt==1) {//좌표 갱신해주기
                            teams[j].r = nr;
                            teams[j].c = cr;
                        }
                    } else{
                        que.push({nr, nc});
                    }
                }
                que.pop();
                num_cnt++;
                if(num_cnt == max_num) {
                    for(int l=0; l<4; l++) {
                        int fr = cr + dr[l];
                        int fc = cc + dc[l];
                        if(fr<0 || fr>=n || fc <0 || fc>=n || lines[fr][fc]==0){
                            continue;
                        }
                        if(lines[fr][fc] == 3) {
                            lines[cr][cc] = 3;
                            lines[fr][fc] = 5+j;
                            break;
                        }
                    }
                }
            }
            cout <<" sfsdfsaaa" <<endl;
        }
        // 공 던지기 (dir, 좌표)

        int ball_location = i % n;
        switch(dir) {
            case 0:
                moveRight(ball_location);
                break;
            case 1:
                moveUp(ball_location);
                break;
            case 2:
                moveLeft(ball_location);
                break;
            case 3:
                moveBottom(ball_location);
                break;
        }
        if((i+1)%n==0) {
            // 방향 변경 (3번 - 4번 찾기)
            dir++;
        }
    }

    cout <<final <<'\n';
    return 0;
}