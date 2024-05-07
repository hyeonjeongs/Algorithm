#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 문제 접근
 * 정수 범위 2^32까지 int 범위, 효율성 문제
 * 순차탐색 -> 100억 초과(시간초과)
 * 이진탐색으로 접근
 */
bool binarySearch(int left, int right, vector<int>& a, int input){
    while(left<=right){
        int mid = (left+ right)/2;

        if(a[mid] == input){
            return true;
        }
        if(a[mid] < input){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, input;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end()); // 오름차순 정렬

    cin>>m;
    while(m--){
        cin>> input;
        cout<< binarySearch(0, n-1, a, input) <<'\n';
    }
    return 0;
}