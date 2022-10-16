#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int v = 10001;
vector<int> color[v];

int main() {
    int n;
    int distance = 0;
    cin >> n;


    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        color[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        sort(color[i].begin(), color[i].end());
    }


    for (int i = 1; i <= v; i++) {
        if (color[i].empty() || color[i].size() == 1)
            continue;
        for (int j = 0; j < color[i].size(); j++) {
            if (j == 0)
                distance += color[i][1] - color[i][0]; // �� ��
            else if (j == color[i].size() - 1)
                distance += color[i][color[j].size() - 1] - color[i][color[j].size() - 2];
            else {
                int left = color[i][j - 1];
                int right = color[i][j + 1];

                distance += min(color[i][j] - left, right - color[i][j]);
            }
        }
    }

    cout << distance << '\n';
}
