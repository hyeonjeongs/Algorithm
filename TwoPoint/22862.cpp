#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;

    cin >> n >> k;
    vector<long long> num(n, 0);
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    int ri =0, li =0;
    int cnt = 0;
    int result = 0;
    int length=0;
    while(ri<n && li <= ri) {

        if(cnt > k) {
            if(num[li]%2==0) {
                length--;
            }else {
                cnt--;
            }
            li++;
        } else {
            if(num[ri]%2==0) {
                length++;
                result = max(result, length); // 이거 위치 잘못 선정해서
            }else {
                cnt++;
            }
            ri++; // 여기 ri 먼저 증가시키면 인덱스 0인거는 포함이 안되니까 오류
        }
    }

    cout << result <<'\n';
    return 0;
}