#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

vector<bool> checked;

int n;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

struct DATA{
    int sx;
    int sy;
    int ex;
    int ey;
};

int sx = 100, sy = 100, ex = -1, ey = -1;
vector<vector<int>> copy_game;
vector<vector<int>> copy_table;
vector<vector<bool>> game_visited;
vector<vector<bool>> table_visited;

vector<DATA> table_loc;
vector<bool> table_checked;

bool outOfBounds(int x, int y) {
    return x<0 || x>=n || y<0 || y>=n;
}

void dfsTable(int y, int x) {
    table_visited[y][x] = true;

    sx = min(sx, x);
    sy = min(sy, y);
    ex = max(ex, x);
    ey = max(ey, y);

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(outOfBounds(nx, ny) || table_visited[ny][nx]) {
            continue;
        }
        if(copy_table[ny][nx] == 1) {
            dfsTable(ny, nx);
        }
    }
}

void gameTable(int y, int x) {
    table_visited[y][x] = true;

    sx = min(sx, x);
    sy = min(sy, y);
    ex = max(ex, x);
    ey = max(ey, y);

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(outOfBounds(nx, ny) || table_visited[ny][nx]) {
            continue;
        }
        if(copy_table[ny][nx] == 0) {
            gameTable(ny, nx);
        }
    }
}
bool isSame(DATA location) {
    for(int a=0; a<=location.ey-location.sy; a++) {
        for(int b=0; b<=location.ey-location.sx;b++) {
            if(copy_game[location.sy+a][location.sx+b] != copy_table[sy+a][sx+b]) {
                return false;
            }
        }

    }
    return true;
}
bool assignBoard() {
    if(!table_checked[i]) {
        for(int i=0; i<table_loc.size(); i++) {
            if(isSame(table_loc[i])){
                return true;
            }


            for(int j=0;j<3; j++) { // 회전

            }
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    n = game_board.size();

    game_visited.assign(n, vector<bool> (n, false));
    table_visited.assign(n, vector<bool> (n, false));

    copy_game = game_board;
    copy_table = table;

    for(int i=0;i <n; i++) {
        for(int j=0; j<n; j++) {
            if(copy_table[i][j]==1) {
                sx = 100, sy = 100, ex = -1, ey = -1;
                dfsTable(i, j);
                table_loc.push_back({sx, sy, ex, ey});
            }
        }
    }
    table_checked.assign(table_loc.size(), false);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(copy_game[i][j] == 0) {
                sx = 100, sy = 100, ex = -1, ey = -1;
                gameTable(i, j);
                assignBoard();
            }
        }
    }

    return answer;
}