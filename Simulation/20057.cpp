#include <iostream>
#include <vector>

using namespace std;
int n;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int ddx[4][10] = {
        {1,1,0,0,0,0,-1,-1,-2,-1},
        {-1,1,-1,1,-2,2,-1,1,0,0},
        {-1,-1,0,0,0,0,1,1,2,1},
        {-1,1,-1,1,2,-2,1,-1,0,0}
};
int ddy[4][10] = {
        {-1,1,-1,1,-2,2,-1,1,0,0},
        {-1,-1,0,0,0,0,1,1,2,1},
        {-1,1,1,-1,-2,2,-1,1,0,0},
        {1,1,0,0,0,0,-1,-1,-2,-1}
};

int number[] = {1,1,7,7,2,2,10,10,5,0};
vector<vector<int>> sand;
int result = 0;

bool outOfRange(int x, int y) {
    
    return x>=0 && y>=0 && x<n && y<n;
}

void windSand(int x, int y, int direction) {
    int amount = sand[y][x];
    int reminder = sand[y][x];
    sand[y][x] = 0;

    for(int i=0; i<10; i++) {
        int num = amount * number[i] /100;
        if(i==9) {
            num = reminder;
        }
        int nx = x + ddx[direction][i];
        int ny = y + ddy[direction][i];
        reminder -= num;

        if(outOfRange(nx, ny)){
            sand[ny][nx] += num;
        } else {
            result += num;
        }
    }
}


void moveTornado() {

     int dist = 1;
     int cnt = 0;
     int direction = 0;
     int cx = n/2;
     int cy = n/2;

     while(1) {
         for(int i=0; i<dist; i++) {
             int nx = cx + dx[direction];
             int ny = cy + dy[direction];
             if(nx==-1 && ny ==0) {
                 return;
             }
             if(sand[ny][nx] != 0){
                 windSand(nx, ny, direction);
             }

             cx = nx;
             cy = ny;
         }

         cnt++;
         direction = (direction +1)%4;

         if(cnt==2) {
             cnt=0;
             dist++;
         }

     }
 }

int main() {

    cin>> n;
    sand.assign(n, vector<int>(n,0));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            cin >>sand[i][j];
        }
    }

    moveTornado();

    cout << result <<'\n';

    return 0;
}