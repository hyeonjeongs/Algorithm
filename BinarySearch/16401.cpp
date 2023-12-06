#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cookieNum(vector<int> &cookie, int mid){
    int cnt=0;
    for(int i=cookie.size()-1; i>=0; i--){
        if(cookie[i]<mid)
            break;
        cnt += cookie[i]/mid;
    }

    return cnt;
}

int cookieLength(int left, int right, vector<int> &cookie, int m){
    int result; //과자 길이
    while (left<=right){
        int mid = (left + right)/2;
        int cnt = cookieNum(cookie, mid); // 이 구간에 과자 몇 명한테 줄 수있는지

        if(cnt >= m){ // 과자 길이 늘리기 가능
            left = mid+1;
            result = mid;
        }
        else{
            right = mid-1;
        }
    }
    return result;
}

/*
 * left : 과자 최소 길이
 * right : 과자 최대 길이
 */
int main(){
    int m, n;
    cin>> m>>n;
    vector<int> cookie(n,0);

    for(int i=0; i<n; i++){
        cin>> cookie[i];
    }

    sort(cookie.begin(), cookie.end());

    cout<<cookieLength(1, cookie[cookie.size()-1],cookie,m);

    return 0;
}