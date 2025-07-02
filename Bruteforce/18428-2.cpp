#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pi;

vector<pi> teachers;
int n;
string result = "NO";
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
void findStudents(vector<vector<char>> seats) {
    for(int i=0; i<teachers.size(); i++) {
        int x = teachers[i].first;
        int y = teachers[i].second;
        for(int j=0; j<4; j++) {
            int nx = x;
            int ny = y;
            while(1) {
                nx += dx[j];
                ny += dy[j];
                if(nx<0 || nx>=n || ny<0 || ny>=n) {
                    break;
                }
                if(seats[ny][nx] == 'O') {
                    break;
                }
                if(seats[ny][nx] == 'S') {
                    return;
                }
            }
        }
    }
    result = "YES";
}

void findLocation(vector<vector<char>> seats, int cnt, int x, int y) {
    if(cnt==3) {
        findStudents(seats);
        return;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(seats[i][j] == 'X') {
                seats[i][j] = 'O';
                findLocation(seats, cnt+1, j, i);
                seats[i][j] = 'X';
            }
        }
    }
}
int main() {


    cin >> n;
    vector<vector<char>> seats(n, vector<char>(n, ' '));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            char ch;
            cin >> ch;
            seats[i][j] = ch;
            if(ch =='T') {
                teachers.push_back({j, i});
            }
        }
    }
    findLocation(seats, 0, 0,0);

    cout<<result;
    return 0;
}