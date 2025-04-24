#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int, int> pi;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0 , 1, -1};
vector<pi> numbers[6];
int sizes;
int total;

bool outOfBounds(int x, int y) {
    return x<0 || x>=sizes || y<0 || y>=sizes;
}
struct TARGET {
    int r;
    int c;
    int num;
};

int end_r = 0, end_c =0;
int bfsTarget(vector<vector<int>> board, int r, int c) {
    int result = 1e6;
    int targets = board[r][c];
    vector<vector<bool>> visited(sizes, vector<bool>(sizes, false)); // bfs 방문여부 보통어떻게하나보기
    visited[r][c] = true;
    board[r][c] = 0;

    queue<TARGET> que;
    que.push({r,c, 0});

    while(!que.empty()) {
        int cr = que.front().r;
        int cc =que.front().c;
        int nums = que.front().num;

        que.pop();
        if(board[cr][cc] == targets) {

            // cout <<r <<" "<< c << " : " <<cr << "  " << cc << " " << nums << endl;
            if(result >nums+2) {
                result = nums + 2; // enter 개수 추가
                end_r = cr; end_c = cc;
            }
            continue;
        }

        for(int i=0; i<4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(outOfBounds(nc, nr) || visited[nr][nc]) {
                continue;
            }

            if(board[nr][nc] != targets) {
                visited[nr][nc] = true;
            }
            que.push({nr, nc,nums+1});

            int ccr = cr, ccc = cc;

            while(1) { // 앞에 뭐 있을때까지 앞으로
                int nr = ccr + dr[i];
                int nc = ccc + dc[i];
                if(outOfBounds(nr, nc)) {
                    break;
                }

                ccr = nr; ccc = nc;
                if(board[nr][nc]>0) {
                    break;
                }
            }

            if(!visited[ccr][ccc]) {
                if(board[ccr][ccc] != targets) {
                    visited[ccr][ccc] = true;
                }
                que.push({ccr, ccc, nums+1});
            }

        }
    }
    //cout<< result << "< " <<end_r<< " , " << end_c<<endl;

    return result;
}
struct NODE {
    int r;
    int c;
    vector<vector<int>> visited;
    vector<vector<bool>> visit;
    int num;
    int total;
};

int bfs(vector<vector<int>> board, int r, int c) {
    int result = 1e7;
    queue<NODE> que;
    vector<vector<bool>> visits;
    visits.assign(sizes, vector<bool>(sizes, false));
    visits[r][c] = true;

    que.push({r,c, board, visits,0, 0 });
    // 도달했으면 현재 다른놈도 뒤집어져잇는지 확인
    while(!que.empty()) {
        int cr = que.front().r;
        int cc = que.front().c;
        int totals = que.front().total;
        int num = que.front().num;
        vector<vector<int>> visited = que.front().visited;
        vector<vector<bool>> visit = que.front().visit;

        que.pop();

        if(totals==total) {

            result = min(result, num);
            continue;
        }
        if(visited[cr][cc]>0) {

            num += bfsTarget(visited, cr, cc);

            visit[cr][cc]=true; visit[end_r][end_c] = true;
            visited[cr][cc] = 0;
            visited[end_r][end_c] = 0;


            que.push({end_r, end_c, visited, visit, num, totals+2});
            continue;
        }

        for(int i=0; i<4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(outOfBounds(nc, nr) || visit[nr][nc]) {
                continue;
            }
            visit[nr][nc]= true;
            que.push({nr, nc,visited,visit,num+1, totals});
            int ccr = cr, ccc = cc;
            visit[nr][nc]= false;

            while(1) { // 앞에 뭐 있을때까지 앞으로
                int nr = ccr + dr[i];
                int nc = ccc + dc[i];
                if(outOfBounds(nc, nr)) {
                    break;
                }

                ccr = nr; ccc = nc;
                if(board[nr][nc]>0) {
                    break;
                }
            }
            if(!visit[ccr][ccc]) {
                visit[ccr][ccc] = true;
                que.push({ccr, ccc, visited, visit, num+1, totals});
                visit[ccr][ccc] = false;
            }


        }

    }
    return result;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 0;
    sizes = board.size();
    for(int i=0; i<sizes; i++) {
        for(int j=0; j<sizes; j++) {
            if(board[i][j]!= 0) {
                total++;
            }
        }
    }
    answer = bfs(board, r,c);
    return answer;
}