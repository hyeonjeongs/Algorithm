#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n, 0);

    long long result[2] = {0,0};

    long long diff = 1e10;

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int left=0, right =n-1;
    while(right<n && left<right) {
        long long sums = arr[left] + arr[right];
        if(abs(sums)<diff) {
            diff = abs(sums);
            result[0] = arr[left];
            result[1] = arr[right];
            
        }
        if(sums <0) {
            left++;
        } else {
            right--;
        }

    }
    cout << result[0] << " " << result[1] << '\n';

    return 0;
}






/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    long long current = 1e10;
    long long result[2] = {0, 0};
    cin >> n;
    vector<long long> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right =n-1;

    while (left < right) {
        long long nums = arr[left] + arr[right];

        if (current > abs(nums)) {
            current = abs(nums);
            result[0] = arr[left];
            result[1] = arr[right];
        }

        if(nums < 0) {
            left ++;
        } else {
            right --;
        }

    }
    cout << result[0] << " " << result[1] << '\n';
    return 0;
}*/
