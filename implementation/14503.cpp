#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
// 4:25
using namespace std;
typedef pair<int, int> pi;// (r,c)
int dc[] = { 0,-1,0,1 }; // 여기서 남, 북 방향 반대로 해줬어야 했는데 그렇게 안해서 오류
int dr[] = { -1,0,1,0 };

int cleanRoom(int n, int m, int r, int c, int index, vector<vector<int> > room) {
    queue<pi> que;
    int result = 0;

    que.push({r,c});
    
    while (!que.empty()) {
        pi location = que.front();
        int cr = location.first;
        int cc = location.second;

        if (room[cr][cc] == 0) {
            room[cr][cc] = -1; // 청소완료
            result++;
        }
        int num = 0;
        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (room[nr][nc] == 0) {
                num++;
            }

        }
        if (num == 0) { // 빈칸 없으면

            int br = cr + dr[(index + 2) % 4]; // 뒤로가기
            int bc = cc + dc[(index + 2) % 4];
            if (room[br][bc] == 1) {
                break;
            }
            que.pop();
            que.push({ br,bc });
        }
        else {

            index= (index+1)%4;
            int fr = cr + dr[index];
            int fc = cc + dc[index];
            if (room[fr][fc] == 0) {
                que.pop();
                que.push({ fr,fc });
            }


        }
    }
    return result;
}

int main() {

    int n, m;
    int r, c, d;
    int index;
    cin >> n >> m;
    cin >> r >> c >> d;
    index = abs(d - 4) % 4;// 방향

    vector<vector<int> > room(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
    cout<<cleanRoom(n, m, r, c, index, room);

    return 0;
}