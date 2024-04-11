#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dc[] = { 0, 1, 1, 1, 0, -1, -1,-1 };
int dr[] = { -1, -1, 0, 1, 1, 1, 0,-1 };

struct FireBall {
    int r;
    int c;
    int m;
    int s;
    int d;
};
int n;

vector<vector<vector<int>>> location;
vector<FireBall> moveShark(vector<FireBall> ball) {
    for (int i = 0; i < ball.size(); i++) { // 파이어볼 이동

        if (ball[i].m > 0) {
            int nr = 0, nc = 0;


            if (dr[ball[i].d] < 0) {
                int num = n * (ball[i].s / n +1);
                nr = (ball[i].r + dr[ball[i].d] * ball[i].s + num) % n;
            }
            else {
                nr = (ball[i].r + dr[ball[i].d] * ball[i].s) % n;
            }

            if (dc[ball[i].d] < 0) {
                int num = n * (ball[i].s / n + 1);
                nc = (ball[i].c + dc[ball[i].d] * ball[i].s + num) % n;
            }
            else {
                nc = (ball[i].c + dc[ball[i].d] * ball[i].s) % n;
            }

            location[ball[i].r][ball[i].c].erase(remove(location[ball[i].r][ball[i].c].begin(), location[ball[i].r][ball[i].c].end(), i), location[ball[i].r][ball[i].c].end());

            ball[i].r = nr;
            ball[i].c = nc;
            location[nr][nc].push_back(i);
        }

    }

    // 동일한곳에 있는 파이어볼 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (location[i][j].size() > 1) {
                int oddSize = 0, evenSize = 0, mSum = 0, sSum = 0;
                int total = location[i][j].size();

                for (int k = 0; k < total; k++) {
                    int number = location[i][j][k]; // ball index

                    if (ball[number].d % 2 == 0) {
                        evenSize++;
                    }
                    else {
                        oddSize++;
                    }
                    mSum += ball[number].m;
                    sSum += ball[number].s;

                    ball[number].m = 0;
                }


                vector<int> erasers;
                location[i][j] = erasers;


                mSum = mSum / 5;

                sSum = sSum / total; // 여기 오타나서 잘못계산
                if (mSum > 0) {
                    int sz = 0;
                    if (oddSize == total || evenSize == total) {
                        sz = 0;

                    }
                    else {
                        sz = 1;
                    }
                    for (int l= sz; l< 8; l+= 2) {
                        FireBall fireBall = { i, j, mSum,sSum, l };
                        ball.push_back(fireBall);
                        location[i][j].push_back(ball.size() - 1);
                    }


                }

            }

        }
    }

    return ball;
}

int main() {
    int m, k;
    cin >> n >> m >> k;
    vector<FireBall> ball;

    location.assign(n, vector<vector<int>>(n));

    for (int i = 0; i < m; i++) {
        FireBall input;
        cin >> input.r >> input.c >> input.m >> input.s >> input.d;
        input.r--;
        input.c--;
        location[input.r][input.c].push_back(i);

        ball.push_back(input);
    }

    for (int i = 0; i < k; i++) {
        ball = moveShark(ball);
    }

    int result = 0;
    for (int i = 0; i < ball.size(); i++) {

        if (ball[i].m > 0) {
            result += ball[i].m;
        }
    }
    cout << result << '\n';

    return 0;
}