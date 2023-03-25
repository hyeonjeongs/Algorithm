#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> foliomino;
vector<vector<bool>> visited;

vector<int> dx = {0,0,-1,1};
vector<int> dy = {1,-1,0,0};
int result=0;


void makeTetromino(int depth, int x, int y, int sum){
    if(depth == 4){
        result = max(result, sum);
        return;
    }

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >=0 && nx <m && ny >=0 && ny < n && !visited[ny][nx]){
            visited[ny][nx] = true;
            if(depth==2){
                makeTetromino(depth+1, x, y, sum+foliomino[ny][nx]);
            }
            makeTetromino(depth+1, nx, ny, sum+foliomino[ny][nx]);
            visited[ny][nx] = false;
        }
    }

}

int main(){
    cin>>n>>m;
    foliomino.assign(n, vector<int>(m,0));
    visited.assign(n, vector<bool>(m, false));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>foliomino[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = true;
            makeTetromino(1, j, i,foliomino[i][j]);
            visited[i][j] = false;
        }
    }

    cout<<result;
    return 0;
}