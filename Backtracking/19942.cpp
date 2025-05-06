#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int protein, fat, carb, vitamin;
vector<vector<int>> data;
vector<bool> visited;
vector<int> min_arr;
int mins = 1e4;
void backtracking(int p, int f, int c, int v, int cost, int index, vector<int> idx) {
    if(p>=protein && f>=fat && c>=carb && v>=vitamin) {
        if(mins > cost) {
            mins = cost;
            min_arr= idx;
        }
        return;
    }

    for(int i=index+1; i<n; i++) {
        idx.push_back(i);
        backtracking(p+data[i][0], f+data[i][1], c+data[i][2], v+data[i][3], cost+data[i][4], i, idx);
        idx.erase(idx.end() -1);
    }
}

int main() {

    cin >> n;
    cin >> protein >> fat >> carb >> vitamin;
    data.assign(n, vector<int>(5, 0));
    visited.assign(n, false);

    for(int i=0; i<n; i++) {
        for(int j=0; j<5; j++) {
            cin >> data[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        vector<int> idx;
        idx.push_back(i);
        backtracking(data[i][0], data[i][1], data[i][2], data[i][3], data[i][4], i, idx);
    }

    if(mins == 1e4) {
        cout << "-1";
    } else {
        cout << mins << '\n';
        for(int i=0; i<min_arr.size(); i++) {
            cout << min_arr[i]+1 << " ";
        }
    }

    return 0;

}