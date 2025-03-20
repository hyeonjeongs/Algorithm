#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> arr;
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    arr.assign(n, 0);
    vector<int> checked(d+1, 0);

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int left = 0, right = k-1;

    int maxs = 1;
    int result =1;
    checked[c] = 1;

    for(int i=0; i<k; i++){
        checked[arr[i]]++;
        if(checked[arr[i]]==1) {
            result++;
        }
    }

    while(left<n) {
        checked[arr[left]]--;
        if(checked[arr[left]]<=0){
            result--;
        }
        left++;

        right++;
        if(right>=n) {
            right = right % n;
        }
        checked[arr[right]]++;
        if(checked[arr[right]]==1) {
            result++;
        }
        maxs = max(maxs, result);
    }
    cout << maxs << '\n';
    return 0;
}