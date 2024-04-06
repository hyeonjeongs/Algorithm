#include <iostream>
#include <vector>
// 8:45
using namespace std;

// 굴렸을 때 바깥이면 해당 명령 무시, 출력도 안함

int dx[] = {0,1,-1,0,0};// 동 서 북 남
int dy[] = {0,0,0,-1,1};

vector<int> dice(7);
int map[21][21];
int order[1001];
int x=0, y=0;

void rollEast() {
    dice={0, dice[4],dice[2],dice[1],dice[6],dice[5],dice[3]};
}

void rollWest() {
    dice={0, dice[3],dice[2],dice[6],dice[1],dice[5],dice[4]};
}

void rollNorth() {
    dice={0, dice[5],dice[1],dice[3],dice[4],dice[6],dice[2]};
}
void rollSouth() {
    dice={0, dice[2],dice[6],dice[3],dice[4],dice[1],dice[5]};
}


void moveMap(int num) {
    switch (num) {
        case 1:
            rollEast();
            break;
        case 2:
            rollWest();
            break;
        case 3:
            rollNorth();
            break;
        case 4:
            rollSouth();
            break;
        default:
            break;
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n>>m>>y>>x>>k; // 여기 x,y 반대로 둬서 오류남 (문제 잘 읽자..)

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<k; i++) {
        cin>>order[i];
    }

    for(int i=0; i<k; i++) {
        int num = order[i];
        int nx = x+dx[num];
        int ny = y+dy[num];
        if(nx<0 || nx>=m || ny<0 || ny>=n) {
            continue;
        }
        x = nx; y = ny;
        moveMap(num);

        cout<<dice[1]<<'\n';
        if(map[y][x]==0) {
            map[y][x] = dice[6];
        }else {
            dice[6] = map[y][x];
            map[y][x] = 0;
        }

    }
    return 0;
}