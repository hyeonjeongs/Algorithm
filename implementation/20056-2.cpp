#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;

int dx[] = {0,1,1,1,0,-1,-1,-1};
int dy[] = {-1,-1,0,1,1,1,0,-1};

struct Data {
    int m;
    int s;
    int d;
};

vector<Data> fires[51][51];
vector<Data> news[51][51];
int N, M, K;
void moves(int y, int x) {

    for (int i=0; i<fires[y][x].size(); i++) {
        Data fire = fires[y][x][i];
        int nx = (x + N + dx[fire.d] * fire.s%N)%N;
        int ny = (y + N + dy[fire.d] * fire.s%N)%N;
        news[ny][nx].push_back({fire.m, fire.s, fire.d});
    }
}

void moveNew() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (news[i][j].size()>1) {
                int total_m = 0; // 총 질량
                int total_s=0;
                int ones=0, twos=0;
                for (int l=0; l<news[i][j].size(); l++) {
                    total_m += news[i][j][l].m;
                    total_s +=news[i][j][l].s;
                    if (news[i][j][l].d %2 ==0 ) {
                        twos++;
                    } else {
                        ones++;
                    }
                }
                total_m /= 5;
                total_s /=news[i][j].size();
                news[i][j].clear();
                if (total_m==0) {
                    continue;
                }
                vector<int> dirs;
                if (twos != 0 && ones !=0) {
                    dirs = {1,3,5,7};
                } else {
                    dirs = {0,2,4,6};
                }

                for (int l=0; l<dirs.size(); l++) {
                    news[i][j].push_back({total_m, total_s, dirs[l]});
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fires[i][j] = news[i][j];
        }
    }
}

void clear_arr() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            news[i][j].clear();
        }
    }
}
int main() {

    cin >> N >> M >> K;

    for (int i=0; i<M; i++) {
        int r,c,m,s,d;
        cin >> r >> c >> m >> s >> d;
        fires[r-1][c-1].push_back({m, s, d});
    }

    while (K--) {
        clear_arr();

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (fires[i][j].size()>0) {
                    moves(i, j);
                }
            }
        }
        moveNew();
    }
    int result = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int l=0; l<fires[i][j].size(); l++) {
                result += fires[i][j][l].m;
            }
        }
    }

    cout << result << '\n';
    return 0;
}