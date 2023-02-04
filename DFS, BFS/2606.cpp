#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<bool>> matrix; //인접행렬

int dfs(int n) {
    vector<bool> visited(n + 1, false);
    stack<int> st;
    st.push(1);
    visited[1] = true;

    int cnt = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        for (int i = 1; i <= n; i++) {
            if (matrix[node][i] && !visited[i]) {
                st.push(i);
                visited[i] = true;
                cnt++;
            }
        }
    }


    return cnt;
}


int main() {
    int n, num;
    cin >> n >> num;
    //인접행렬로 구현
    matrix.assign(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = true;
        matrix[b][a] = true;
    }

    cout << dfs(n);

    return 0;
}