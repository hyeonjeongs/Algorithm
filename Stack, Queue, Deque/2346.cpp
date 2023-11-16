#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void solveDeque(vector<int>& balloon, int n) {
    deque<int> deq;
    int num;
    for(int i=1; i<=n; i++) {
        deq.push_back(i);
    }
    num = balloon[deq.front()-1];
    cout<< deq.front() << ' ';
    deq.pop_front();

    for(int i=0; i<n; i++) {
        if(num > 0) {
            for(int j=0; j<num-1; j++) {
                if(!deq.empty()) {
                    int front_num = deq.front();
                    deq.pop_front();
                    deq.push_back(front_num);
                }
            }
        }

        if(num < 0) {
            for(int j=0; j<abs(num); j++) {
                if(!deq.empty()) {
                    int back_num = deq.back();
                    deq.pop_back();
                    deq.push_front(back_num);
                }
            }
        }
        if(!deq.empty()){
            num = balloon[deq.front()-1];
            cout<<deq.front()<<' ';
            deq.pop_front();
        }
    }
}

int main() {

    int n;
    cin>>n;
    vector<int> balloon;

    for(int i=0; i<n; i++) {
        int input;
        cin>>input;
        balloon.push_back(input);
    }

    solveDeque(balloon, n);
}