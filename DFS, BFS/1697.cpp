#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pi;
const int SIZE = 1e5+1;
int main() {
    int n, k;

    cin >> n >> k;
    vector<int> location(SIZE, 0);
    vector<bool> visited(SIZE, false);
    queue<pi> que;

    int time = 1e5+1;
    que.push({n, 0});
    visited[n] = true;


    while (!que.empty()) {
        int current_loc = que.front().first;
        int times = que.front().second;
        que.pop();
        if (current_loc == k) {
            time = min(time, times);
            break;
        }

        vector<int> next_location = {current_loc-1, current_loc+1, current_loc*2};

        for (int i=0; i<3; i++) {
            if (next_location[i]>=0 && next_location[i]<SIZE && !visited[next_location[i]]) {
                que.push({next_location[i], times+1});
                visited[next_location[i]] = true;
            }
        }
    }
    cout << time << '\n';

    return 0;;
}