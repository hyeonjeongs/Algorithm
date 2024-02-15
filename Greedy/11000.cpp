#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;
int main() {
    priority_queue<int, vector<int>, greater<int>> que; // 작은 값이 우선시

    int n;
    cin>>n;
    vector<pi> class_time;

    vector<int> s(n,0);
    vector<int> t(n,0);

    for(int i=0; i<n; i++) {
        int start, end;
        cin>> start >>end;
        class_time.push_back({start, end});
    }
    sort(class_time.begin(), class_time.end());

    que.push(class_time[0].second);
    for(int i=1; i<class_time.size(); i++) {
        que.push(class_time[i].second);

        if(class_time[i].first >= que.top()) {
            que.pop();
        }
    }

    cout << que.size() <<'\n';
    return 0;
}