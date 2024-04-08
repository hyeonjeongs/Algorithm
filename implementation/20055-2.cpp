#include <iostream>
#include <vector>
/*
 * 실수
 * 2*n이 아니라 n을 기준으로 구함
 * 로봇 이동하는 구간에서 for문에 i-1 부분 -> 2*n 도 해줘야함
 */
using namespace std;

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> container(n*2, 0);
    vector<bool> robot(2*n, false); // 로봇 올라가 있는지

    for(int i=0; i<2*n; i++) {
        cin>> container[i];
    }

    int front =0, rear=n-1;
    int cnt=0;
    int step=0;
    int num = 2*n;
    while(1) {
        step++;

        // 로봇 내리기
        robot[rear] = false;

        // 포인트 이동
        front = (front-1+num)%num;
        rear = (rear-1+num)%num;

        // 로봇 이동시키기
        for(int i=rear; i!=front; i=(i-1+num)%num) {
            if(i==rear && robot[i]) {
                robot[i] = false;
                continue;
            }
            if(robot[i]) {
                if(container[(i+1)%num]>0 && !robot[(i+1)%num]) {
                    container[(i+1)%num]--;
                    robot[(i+1)%num] = true;
                    robot[i] = false;
                    if(container[(i+1)%num]<=0){
                        cnt++;
                    }
                }
            }
        }

        if(container[front]>0) {
            robot[front] = true;
            container[front]--;
            if(container[front]<=0){
                cnt++;
            }
        }

        if(cnt>=k) {
            break;
        }

    }
    cout<< step<<'\n';
    return 0;
}