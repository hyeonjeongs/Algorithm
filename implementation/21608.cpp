#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
typedef pair<int,int> pi;

bool cmp(pi a, pi b) {
    if(a.first== b.first) {
        return a.second <b.second;
    }
    return a.first < b.first;
}

vector<vector<int>> seatStudents(vector<int> order, vector<vector<int>> prefer, int n) {

    vector<vector<int>> seat(n, vector<int>(n, 0));
    vector<vector<int>> blank(n, vector<int>(n,0));

    // 빈칸 개수 채우기
    for(int i=0;i <n; i++) {
        for(int j=0; j<n; j++) {
            if(i==0 || i ==n-1 || j==0 || j==n-1) {
                blank[i][j] = 3;
            }else {
                blank[i][j] =4;
            }
        }
    }
    blank[0][0]=blank[n-1][n-1]=blank[0][n-1]=blank[n-1][0] = 2;

    vector<pi> clears;
    for(int l=0; l<order.size(); l++) {
        int preferNum =0;
        vector<pi> xy;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(seat[i][j]>0){
                    continue;
                }
                int cnt =0;
                for(int k=0; k<4; k++) {
                    int nx = j+dx[k];
                    int ny = i+dy[k];
                    if(nx<0 || nx>=n || ny<0 || ny>=n) {
                        continue;
                    }
                    for(int m=0; m<4; m++) { // 선호하는거 있는지 확인
                        if(seat[ny][nx]==prefer[order[l]][m]) {
                            cnt++;
                        }
                    }

                }
                if(cnt>preferNum) {
                    xy = clears;
                    xy.push_back({i,j});
                    preferNum = cnt;
                }
                if(cnt==preferNum) {
                    xy.push_back({i, j});
                }

            }
        }
        // 좋아하는 개수 한개이면

        if(xy.size()==1) {
            seat[xy[0].first][xy[0].second] = order[l];
            for(int i=0; i<4; i++) {
                int nx = dx[i] + xy[0].second;
                int ny = dy[i] + xy[0].first;
                if(nx<0 || nx>=n || ny<0|| ny>=n) {
                    continue;
                }
                blank[ny][nx]--;
            }
            continue;
        }
        int blackNum = 0;
        vector<pi> blankXY;
        for(int m=0; m<xy.size(); m++) {
            if(blackNum==blank[xy[m].first][xy[m].second]){
                blankXY.push_back(xy[m]);
            }
            if(blackNum<blank[xy[m].first][xy[m].second]) {
                blankXY = clears;
                blankXY.push_back(xy[m]);
                blackNum = blank[xy[m].first][xy[m].second];
            }
        }
        // 빈칸 한개이면
        if(blankXY.size()==1) {
            seat[blankXY[0].first][blankXY[0].second] = order[l];
            for(int i=0; i<4; i++) {
                int nx = dx[i] + blankXY[0].second;
                int ny = dy[i] + blankXY[0].first;
                if(nx<0 || nx>=n || ny<0|| ny>=n) {
                    continue;
                }
                blank[ny][nx]--;
            }

            continue;
        }
        sort(blankXY.begin(), blankXY.end(),cmp);
        seat[blankXY[0].first][blankXY[0].second] = order[l];
        for(int i=0; i<4; i++) {
            int nx = dx[i] + blankXY[0].second;
            int ny = dy[i] + blankXY[0].first;
            if(nx<0 || nx>=n || ny<0|| ny>=n) {
                continue;
            }
            blank[ny][nx]--;
        }
    }

    return seat;
}

int preferNum(vector<vector<int>> seat, vector<vector<int>> prefer, int n) {
    int cnt=0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int current=0;
            for(int l=0; l<4; l++) {
                int nx = dx[l] + j;
                int ny = dy[l] + i;
                if(nx<0 || nx>=n || ny<0 || ny>=n) {
                    continue;
                }
                for(int m=0; m<4; m++) {
                    if(seat[ny][nx] == prefer[seat[i][j]][m]){
                        current++;
                    }
                }
            }
            switch(current) {
                case 0:
                    cnt+=0;
                    break;
                case 1:
                    cnt+=1;
                    break;
                case 2:
                    cnt+=10;
                    break;
                case 3:
                    cnt+=100;
                    break;
                case 4:
                    cnt+=1000;
                    break;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> seat;
    vector<vector<int>> prefer(n*n+1, vector<int>(4,0));
    vector<int> order;

    for(int i=1; i<=n*n; i++) {
        int a;
        cin >>a;
        cin>> prefer[a][0]>> prefer[a][1] >> prefer[a][2] >> prefer[a][3];
        order.push_back(a);
    }

    seat = seatStudents(order, prefer, n);

    cout<<preferNum(seat, prefer, n);
    return 0;
}