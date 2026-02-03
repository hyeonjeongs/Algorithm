#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
typedef pair<int, int> pi;
vector<vector<int>> location{{6,2}, {6,2}, {6,2},{6,2}};

void moveWheel(int num, int dir, vector<vector<int>> &wheel) {
    dir = -(dir);
    queue<pi> que;
    que.push({num, dir});
    vector<bool> visited(4, false); // visited로 다시 방문하는거 고려안헀었음
    visited[num] = true;

    while (!que.empty()) {

        int number = que.front().first;
        int direction = que.front().second;
        que.pop();
        if (number >= 1 && !visited[number-1] && wheel[number-1][location[number-1][1]] != wheel[number][location[number][0]]) {
            visited[number-1] = true;
            que.push({number-1, -(direction)});
        }
        if (number < 3 && !visited[number+1] && wheel[number+1][location[number+1][0]] != wheel[number][location[number][1]]) {
            visited[number+1] = true;
            que.push({number+1, -(direction)});
        }
        location[number][0] = (location[number][0]+direction+8)%8;
        location[number][1] = (location[number][1]+direction+8)%8;
    }

}
int main() {

    vector<vector<int>> wheel(4, vector<int>(8,0));
    for (int i=0; i<4; i++) {
        for (int j=0; j<8; j++) {
            scanf("%1d", &wheel[i][j]);
        }
    }
    int k;
    cin >> k;
    for (int i=0; i<k; i++) {
        int number, dir;
        cin >> number >> dir;
        moveWheel(number-1, dir, wheel);
    }

    int result = 0;
    for (int i=0; i<4; i++) {
        int num = (location[i][1]+6)%8; // 여기 0번째 인덱스로 했어서 틀림
        if (wheel[i][num] == 1) {
            result += pow(2, i);
        }
    }
    cout << result << endl;

    return 0;
}