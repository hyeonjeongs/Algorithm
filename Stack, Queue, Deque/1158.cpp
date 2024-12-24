#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n>> k;
    queue<int> que;
    for(int i=1; i<=n ;i++){
        que.push(i);
    }

    cout << "<";
    while(que.size()>1) {
        for(int i=1; i<k; i++) {
            int front = que.front();
            que.pop();
            que.push(front);
        }
        cout << que.front()<< ", ";
        que.pop();

    }
    cout << que.front() << ">";
    return 0;
}

/*
#include<iostream>
#include<queue>

using namespace std;
queue<int> result;
int main() {
    int k, n;

    cin >> n >> k;
    int num;

    for (int i = 1; i <= n; i++) {
        result.push(i);
    }

    cout << "<";

    while (result.size() > 1) {
        for (int i = 1; i < k; i++) {
            num = result.front();
            result.pop();
            result.push(num);
        }
        cout << result.front()<<", ";
        result.pop();
    }
    cout << result.front() << ">";

    return 0;

}
*/
