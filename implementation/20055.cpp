// index 이용한 방법으로도 풀어 보기
// deque로 푸는 것도한 번 더 확인하기

# include <iostream>
# include <vector>
# include <deque>

using namespace std;

struct info {
    int power; // 벨트의 내구도
    bool robot;  // 로봇 존재 여부
};

void rotate(deque<info> &belt, int n){
    belt.push_front(belt.back());
    belt.pop_back();

    if(belt[n-1].robot){
        belt[n-1].robot = false;
    }
}

void move(deque<info> &belt, int n) {

    for(int i=n-2; i>=0; i--){
        // 현재칸에 로봇 존재하고, 다음칸 내구성이 0보다크고, 다음칸에 로봇 없어야하함
        if(belt[i].robot && belt[i+1].power>0 && !belt[i+1].robot){
            belt[i].robot = false;
            belt[i+1].robot = true;
            belt[i+1].power--;
        }

    }

    if(belt[n-1].robot){
        belt[n-1].robot = false;
    }
}

void put(deque<info> &belt) {
    if(belt[0].power>0){
        belt[0].robot = true;
        belt[0].power--;
    }
}

int zeroBelt(int n, deque<info> &belt) {
    int cnt = 0;
    for(int i =0; i< 2*n; i++){
        if(belt[i].power == 0){
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, k;

    cin>> n>>k;
    deque<info> belt(2*n, {0,false});

    for(int i=0; i< 2*n; i++){
        cin>> belt[i].power;
    }

    int level =0;
    while(1){
        rotate(belt, n); // 한 칸 회줜하기
        move(belt, n); // 로봇 이동시키기
        put(belt); //로봇 올리기

        int num = zeroBelt(n, belt); // 내구도 0 인거 체크하기
        level++;

        if(num>=k){
            cout<< level << '\n';
            return 0;
        }
    }

}
