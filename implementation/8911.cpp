#include <iostream>
#include <vector>

using namespace std;

int turtleMinArea(string str) {
    // 북동남서
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int min_x = 0, min_y = 0, max_x = 0, max_y = 0;
    int direction = 0; // 북:0, 동:1, 남:2, 서:3

    pair<int, int> cur = {0, 0};

    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
            case 'F':
                cur = {cur.first + dx[direction], cur.second + dy[direction]};
                break;
            case 'B':
                cur = {cur.first - dx[direction], cur.second - dy[direction]};
                break;
            case 'L':
                direction = (direction + 3) % 4;
                break;
            case 'R':
                direction = (direction + 1) % 4;
                break;

        }
        min_x = min(min_x, cur.first);
        min_y = min(min_y, cur.second);
        max_x = max(max_x, cur.first);
        max_y = max(max_y, cur.second);
    }

    return (max_x - min_x) * (max_y - min_y);
}
int main() {
    int t;
    string str;
    cin >> t;

    while (t--) {
        cin >> str;
        cout << turtleMinArea(str) << '\n';
    }
}