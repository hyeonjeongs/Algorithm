#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
struct Node{
    int x;
    int y;
    vector<vector<int>> loc;
};
pi red, blue, red_des, blue_des;
int n, m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int result = 1e4;

bool out_of_bound(int x, int y) {
    return x<0 || x>=m || y<0 || y>=n;
}
void move_blue_puzzle(vector<vector<int>> maze, vector<vector<int>> red_loc) {
    vector<vector<int>> blue_arr(n, vector<int>(m, 0));
    blue_arr[blue.second][blue.first] =1;
    queue<Node> blue_loc;
    blue_loc.push({blue.first, blue.second, blue_arr});
    while(!blue_loc.empty()) {
        int cx = blue_loc.front().x;
        int cy = blue_loc.front().y;
        vector<vector<int>> loc = blue_loc.front().loc;
        blue_loc.pop();
        
        if(cx ==blue_des.first && cy ==blue_des.second) {
            if(red_loc[cy][cx]>0 &&red_loc[cy][cx]>=loc[cy][cx]) {
                continue;
            }    
            int results = max(red_loc[red_des.second][red_des.first],loc[cy][cx]);
            result =min(results-1, result);
            break;
        }
        
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(out_of_bound(nx, ny) ||loc[ny][nx]>0 || maze[ny][nx]==5 ) {
                continue;
            }
            if(loc[cy][cx]+1 == red_loc[ny][nx]) { //같은 위치로 이동
                continue;
            }
            if(loc[cy][cx]==red_loc[ny][nx] && red_loc[cy][cx]==loc[cy][cx]+1) { //바꾸며 이동
                continue;
            }
            // 2.이렇게 도착지에 있는경우 체크해주는거필요함
            if(nx == red_des.first && ny == red_des.second) { 
                if(red_loc[ny][nx] <= loc[cy][cx]+1) {
                    continue;
                }
            }
            int num = loc[ny][nx];
            loc[ny][nx] = loc[cy][cx]+1;
            blue_loc.push({nx, ny, loc});
            loc[ny][nx] =num; // 1. 여기부분 (bfs랑은 안맞는거같긴함)
           
        }
    }
}
void move_red_puzzle(vector<vector<int>> maze) {
    vector<vector<int>> red_arr(n, vector<int>(m, 0));
    red_arr[red.second][red.first] =1;
    queue<Node> red_loc;
    red_loc.push({red.first, red.second, red_arr});
    
    while(!red_loc.empty()) {
        int cx = red_loc.front().x;
        int cy = red_loc.front().y;
        vector<vector<int>> loc = red_loc.front().loc;
        red_loc.pop();
        if(cx ==red_des.first && cy ==red_des.second) {
            move_blue_puzzle(maze, loc);
            continue;
        }
        
        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(out_of_bound(nx, ny) ||loc[ny][nx]>0 || maze[ny][nx]==5) {
                continue;
            }
   
            int num = loc[ny][nx];
            loc[ny][nx] = loc[cy][cx]+1;
            red_loc.push({nx, ny, loc});
            loc[ny][nx] =num;
        }
    }
    
}
int solution(vector<vector<int>> maze) {
    int answer = 0;
    n = maze.size();
    m= maze[0].size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int num = maze[i][j];
            if(num==1) {
                red = {j, i};
                maze[i][j] = 0;
            }
            if(num==2) {
                blue = {j,i};
                maze[i][j] = 0;
            }
            if(num==3){
                red_des = {j, i};
                maze[i][j] = 0;
            }
            if(num==4) {
                blue_des = {j, i};
                maze[i][j] = 0;
            }
        }
    }
    move_red_puzzle(maze);
    answer = result;
    if(result==1e4){
        answer= 0;
    }
    return answer;
}