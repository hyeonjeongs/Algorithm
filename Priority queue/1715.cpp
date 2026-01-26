#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    while (n--) {
        int input;
        cin>>input;
        pq.push(input);
    }
    int result =0;
    while (pq.size()>=2) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        pq.push(a+b);
        result += (a+b);
    }
    cout << result;
}