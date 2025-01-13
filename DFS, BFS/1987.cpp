#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector<bool> visited;
vector<vector<char>> alpha;
vector<vector<bool>> moves;
int r,c;

int max_size = 0;

void dfs(int x, int y, int depth) {

    max_size = max(max_size, depth);

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<=0 || nx>c || ny<=0 || ny>r) {
            continue;
        }
        if(visited[alpha[ny][nx]-'A'] ) {
            continue;
        }
        visited[alpha[ny][nx]-'A'] = true;


        dfs(nx, ny, depth+1);

        visited[alpha[ny][nx]-'A'] = false;


    }

}
int main() {

    cin >> r>> c;
    alpha.assign(r+1, vector<char>(c+1, ' '));
    moves.assign(r+1, vector<bool>(c+1, false));
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            cin >> alpha[i][j];
        }
    }
    visited.assign(26,false);

    visited[alpha[1][1]-'A'] = true;
    moves[1][1] = true;
    dfs(1,1,1);

    cout << max_size << '\n';

    return 0;
}