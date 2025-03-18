#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, cmp> starts;
    priority_queue<int, vector<int>, cmp> ends;

    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        starts.push(a);
        ends.push(b);
    }

    int result = 0;
    while(!starts.empty()) {
        int back = ends.top();
        int front = starts.top();

        if(front < back) {
            result++;
        } else {
            ends.pop();
        }
        starts.pop();
    }

    cout << result << '\n';

    return 0;
}