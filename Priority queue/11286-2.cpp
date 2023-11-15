#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(const int &a, const int &b) {
        if(abs(a)==abs(b)) {
            return a>b;
        }
        return abs(a)>abs(b);
    }
};

int main() {
    priority_queue<int, vector<int>, cmp> pq;
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int input;
        cin>>input;
        if(input!=0) {
            pq.push(input);
            continue;
        }
        if(!pq.empty()){
            cout<<pq.top()<<'\n';
            pq.pop();
            continue;
        }
        cout<<0<<'\n';

    }

    return 0;
}