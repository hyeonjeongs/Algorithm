#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

void buildBo(int x, int y, int b, vector<vector<vector<int>>>& build, int n) {
    bool isPossible = false;
    if (b == 0) { // 삭제
        for (int i = 0; i < build[y][x].size(); i++) {
            if (build[y][x][i] == 1) {
                build[y][x].erase(build[y][x].begin() + i);
                break;
            }
        }
    } else { // 설치
        if (y - 1 >= 0 && build[y - 1][x].size() > 0) {
            for (int i = 0; i < build[y - 1][x].size(); i++) {
                if (build[y - 1][x][i] == 0) {
                    isPossible = true;
                    break;
                }
            }
        } else if (y - 1 >= 0 && x + 1 <= n && build[y - 1][x + 1].size() > 0) {
            for (int i = 0; i < build[y - 1][x + 1].size(); i++) {
                if (build[y - 1][x + 1][i] == 0) {
                    isPossible = true;
                    break;
                }
            }
        } else if ((x - 1 >= 0 && build[y][x - 1].size() > 0) && (x + 1 <= n && build[y][x + 1].size() > 0)) {
            int cnt = 0;
            for (int i = 0; i < build[y][x - 1].size(); i++) {
                if (build[y][x - 1][i] == 1) {
                    cnt++;
                    break;
                }
            }
            for (int i = 0; i < build[y][x + 1].size(); i++) {
                if (build[y][x + 1][i] == 1) {
                    cnt++;
                    break;
                }
            }
            if (cnt == 2) {
                isPossible = true;
            }
        }
        if(isPossible) {
            build[y][x].push_back(1);
        }

    }
}

void buildColumn(int x, int y, int b, vector<vector<vector<int>>>& build, int n) {
    bool isPossible = false;
    if (b == 0) { // 삭제
        for (int i = 0; i < build[y][x].size(); i++) {
            if (build[y][x][i] == 0) {
                build[y][x].erase(build[y][x].begin() + i);
                break;
            }
        }
    } else { // 설치
        if (y == 0) {
            isPossible = true;
        } else if (y - 1 >= 0 && build[y - 1][x].size() > 0) {
            for (int i = 0; i < build[y - 1][x].size(); i++) {
                if (build[y - 1][x][i] == 0) {
                    isPossible = true;
                    break;
                }
            }
        } else if (x - 1 >= 0 && build[y][x - 1].size() > 0) {
            for (int i = 0; i < build[y][x - 1].size(); i++) {
                if (build[y][x - 1][i] == 1) {
                    isPossible = true;
                    break;
                }
            }
        } else if (build[y][x].size() > 0) {
            for (int i = 0; i < build[y][x].size(); i++) {
                if (build[y][x][i] == 1) {
                    isPossible = true;
                    break;
                }
            }
        }
        if(isPossible) {
            build[y][x].push_back(0);
        }

    }
}

bool cmp(vector<int> a, vector<int> b) {
    if (a[0] != b[0]) return a[0] < b[0];
    if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<vector<int>>> build(n + 1, vector<vector<int>>(n + 1));

    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];

        if (a == 0) {
            buildColumn(x, y, b, build, n);
        } else {
            buildBo(x, y, b, build, n);
        }
    }

    for (int y = 0; y <= n; y++) {
        for (int x = 0; x <= n; x++) {
            for (int k = 0; k < build[y][x].size(); k++) {
                vector<int> adds = {x, y, build[y][x][k]};
                answer.push_back(adds);
            }
        }
    }

    sort(answer.begin(), answer.end(), cmp);
    return answer;
}