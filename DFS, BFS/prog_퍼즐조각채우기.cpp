#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<int,int> pi;
vector<vector<bool>> visited;

vector<vector<pi>> puzzle;
vector<vector<pi>> empties;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int answer = 0;
int num=0;

vector<pi> rePositionZero(vector<pi> piece) {
    int min_x= num;
    int min_y = num;
    for(int i=0; i<piece.size(); i++) {
        min_x = min(min_x, piece[i].first);
        min_y = min(min_y, piece[i].second);
    }

    for(int i=0;i <piece.size(); i++) {
        piece[i].first -= min_x;
        piece[i].second -= min_y;
    }

    return piece;
}

vector<pi> bfs(int x, int y, vector<vector<int>> table, int value) {

    queue<pi> que;
    vector<pi> result;
    result.push_back({x,y});
    que.push({x,y});
    visited[y][x] = true;
    while(!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();

        for(int i=0; i<4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(new_x>=0 && new_x<num && new_y>=0 && new_y<num && !visited[new_y][new_x] && table[new_y][new_x]==value) {
                visited[new_y][new_x] = true;

                que.push({new_x, new_y});
                result.push_back({new_x, new_y});
            }
        }
    }
    return result;

}
vector<pi> rotation(vector<pi> table) {
    int row = 0;
    for(int i=0; i<table.size(); i++) {
        row = max(row, table[i].first); // row 구하기
    }

    for(int i=0; i<table.size(); i++) {
        int x = table[i].second;
        int y = table[i].first;
        table[i].first= x;
        table[i].second = row-y;
    }
    return table;

}

void matchPuzzle() {
    vector<bool> puzzle_visit(puzzle.size(), false);

    for(int p=0; p<empties.size(); p++) {
        vector<pi> board = empties[p];
        for(int index=0; index<puzzle.size(); index++) {
            vector<pi> puz = puzzle[index];
            if(puzzle_visit[index])
                continue;
            if(board.size() != puz.size()) {
                continue;
            }
            bool status = false;
            for(int r=0; r<4; r++) {
                int cnt =0;
                for(int i=0; i<board.size(); i++) {
                    for(int j=0; j<puz.size(); j++) {
                        if(board[i].first == puz[j].first && board[i].second == puz[j].second) {
                            cnt++;
                            continue;
                        }
                    }
                }
                if(cnt != board.size()) {
                    puz = rotation(puz);
                    continue;
                }

                answer += board.size();
                puzzle_visit[index] = true;
                status = true;
                break;
            }
            if(status) {
                break;
            }
        }
    }

}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {

    num = game_board.size();
    visited.assign(num, vector<bool>(num,false));
    for(int i=0; i<num; i++) {
        for(int j=0; j<num; j++) {
            if(!visited[i][j] && game_board[i][j]==0) {
                empties.push_back(rePositionZero(bfs(j, i, game_board,0)));

            }
        }
    }
    
    visited.assign(num, vector<bool>(num,false));

    for(int i=0; i<num; i++) {
        for(int j=0; j<num; j++) {
            if(!visited[i][j] && table[i][j]==1) {
                puzzle.push_back(rePositionZero(bfs(j, i, table,1)));

            }
        }
    }

    matchPuzzle();


    return answer;
}