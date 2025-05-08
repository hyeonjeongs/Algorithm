#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> arr(n,0);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int result = 0;
    int left =0, right=0;
    int cnt = 0;
    int removes=0;
    while(right<n && left<=right) {

        if(removes<=k) {
            if(arr[right]%2==0) {
                cnt++;
                result = max(result, cnt);
            } else {
                removes++;
            }
            right++;
        } else {
            if(arr[left]%2==0) {
                cnt--;
            } else {
                removes--;
            }
            left++;
        }
    }
    cout << result << endl;
    return 0;
}