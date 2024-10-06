#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &R) {
    int li =0, ri=0;
    int result = 0;

    while(li<R.size()) {
        if(R[li]==0) {
            li++;
            continue;
        }
        int maxs=0;
        int cnt=0;
        for(ri=li; ri<R.size(); ri++) {
            if(R[ri]==0) {
                break;
            }
            cnt++;
            maxs = max(maxs, R[ri]);
        }
        li = ri+1;
        result = max(result, maxs*cnt);
    }

    return result;
}
