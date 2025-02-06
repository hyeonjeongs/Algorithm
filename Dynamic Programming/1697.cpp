#include <iostream>
#include <vector>
#include <queue>
#define MAXS 100001

int n,k;
int mins = MAXS;

using namespace std;
typedef pair<int,int> pi;
void bfs() {

    queue<pi> que;
    vector<bool> visited(MAXS, false);
    que.push({n, 0});

    while(!que.empty()) {
        int num = que.front().first;
        int cnt = que.front().second;

        if(num == k) {
            mins = cnt;
            return;
        }
        que.pop();

        if(num!=0 && !visited[num-1]) {
            que.push({num-1, cnt+1});
            visited[num-1] = true;
        }

        if(!visited[num+1]) {
            que.push({num+1, cnt+1});
            visited[num+1] = true;
        }

        if(num*2<MAXS && !visited[num*2]) {
            que.push({num*2, cnt+1});
            visited[num*2] = true;
        }
    }
}

int main()
{
    cin >> n>> k;

    bfs();
    cout<<mins << '\n';
    return 0;

}