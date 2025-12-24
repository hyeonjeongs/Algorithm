#include <string>
#include <vector>

using namespace std;
typedef long long ll;
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    ll deliver_count = 0, pickup_count = 0;

    for(int i=n-1; i>=0 ;i--) {
        long long cnt = 0;
        deliver_count += deliveries[i];
        pickup_count += pickups[i];

        while(1) {
            if(deliver_count<=0 && pickup_count<=0) {
                break;
            }
            deliver_count-= cap;
            pickup_count -= cap;
            cnt++;
        }
        answer += (i+1) * (cnt*2);
    }

    return answer;
}
