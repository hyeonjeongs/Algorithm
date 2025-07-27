#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int result= 1e6;
int counts = 0;
vector<vector<pi>> pairs;
vector<pi> cards;
vector<bool> visited;
vector<bool> pair_visited;
vector<vector<int>> boards;

struct Result {
    int x;
    int y;
    int cnt;
};


bool outOfBounds(int x, int y) {
    return (x<0 || x>=4 || y<0 || y>=4);
}

int findNode(int sx, int sy, int ex, int ey) {
    vector<vector<bool>> visit(4, vector<bool>(4, false));
    visit[sy][sx] = true;
    queue<Result> que;
    que.push({sx, sy, 0});
    int result_num = 0;

    while(!que.empty()) {

        int x = que.front().x;
        int y = que.front().y;
        int cnt = que.front().cnt;
        que.pop();

        if(x== ex && y == ey) {
            result_num = cnt;
            break;
        }

        for(int i=0; i<4; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(!visit[cy][cx] && !outOfBounds(cx, cy)) {
                que.push({cx, cy, cnt+1});
                visit[cy][cx] = true;
            }
            int ccx = x;
            int ccy = y;

            while(1) {
                ccx += dx[i];
                ccy += dy[i];
                if(outOfBounds(ccx,ccy)) {
                    break;
                }
                if(ccx<=0 || ccx>=3 || ccy<=0 || ccy>=3 ||boards[ccy][ccx]!=0 ) {
                    break;
                }
            }
            if(!outOfBounds(ccx, ccy) && !visit[ccy][ccx]) {
                que.push({ccx, ccy, cnt+1});
                visit[ccy][ccx] = true;
            }

        }
    }
    return result_num;
}

void bfs(int sr, int sc, int card_index, int cnt, int move_cnt) {

    pi current = cards[card_index];
    pi last = pi(0,0);
    int number = boards[current.first][current.second];
    for(int i=0; i<2; i++) {
        if(pairs[number][i].first== current.first && pairs[number][i].second== current.second){
            continue;
        }
        last = pairs[number][i];
    }
    if(boards[sr][sc]>0 && cnt ==0) { //처음 시작이 0이 아닌경우 처리
        pi lasts = pi(0,0);
        int number = boards[sr][sc];
        for(int i=0; i<2; i++) {
            if(pairs[number][i].first== sr && pairs[number][i].second== sc){
                continue;
            }
            lasts = pairs[number][i];
        }
        move_cnt += findNode(sc, sr, lasts.second, lasts.first);
        move_cnt +=2;
        sr = lasts.first;
        sc = lasts.second;
        pair_visited[number] = true;
    }
    move_cnt += findNode(sc, sr, current.second, current.first);
    move_cnt += findNode(current.second, current.first, last.second, last.first);
    move_cnt+=2;
    cnt +=2;

    if(counts <= cnt) {
        result = min(result, move_cnt);
        return;
    }

    sr = last.first;
    sc = last.second;


    for(int i=0; i<cards.size(); i++) {
        if(!visited[i] && !pair_visited[boards[cards[i].first][cards[i].second]]) {
            visited[i] = true;
            pair_visited[boards[cards[i].first][cards[i].second]] = true;

            bfs(sr, sc, i, cnt, move_cnt);

            visited[i] = false;
            pair_visited[boards[cards[i].first][cards[i].second]] = false;
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    boards = board;
    int answer = 0;

    pairs.assign(7, vector<pi>());
    pair_visited.assign(7, false);

    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            if(board[i][j]!=0) {
                counts++;
                pairs[board[i][j]].push_back({i, j}); // (r,c);
                cards.push_back({i, j});
            }
        }
    }
    visited.assign(cards.size(), false);


    for(int i=0; i<cards.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            pair_visited[board[cards[i].first][cards[i].second]] = true;
            bfs(r, c, i, 0, 0);
            visited[i] = false;
            pair_visited[board[cards[i].first][cards[i].second]] = false;
        }
    }
    answer = result;

    return answer;
}