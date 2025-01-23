#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    long long min_size = 1e10;
    cin >> n >> s;
    vector<long long> arr(n+1, 0);

    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        arr[i+1] = num + arr[i];
    }

    long long left = 0, right = 1;
    long long sum = 0;
    while (right<=n && left <= right) {
        sum = arr[right]- arr[left];
        if(sum >= s) {
            min_size = min(min_size,right - left);
            left++;
        }else{
            right++;
        }
    }

    if(min_size == 1e10) {
        cout << 0;
    }else {
        cout << min_size;
    }

    return 0;
}