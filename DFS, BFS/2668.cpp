#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<int> arr;
vector<bool> visited;
vector<int> result;
int n;
void dfs(int start, int num) {

    if (visited[num]) {
        if (start == num) {
            result.push_back(start);

        }
        return;
    }
    visited[num] = true;
    dfs(start, arr[num]);

}

int main() {

    cin >> n;
    arr.assign(n+1, 0);
    visited.assign(n+1, false);


    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    for (int i=1; i<=n; i++) {
        visited.assign(n, false);
        dfs(i, i);
    }

    cout <<result.size() << '\n';
    for (auto it: result) {
        cout << it << '\n';
    }
    return 0;
}