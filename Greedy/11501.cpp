#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    int n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> arr;
        for (int i=0; i<n; i++) {
            int input;
            cin >> input;
            arr.push_back(input);
        }
        int maxs= 0;
        long long result = 0;
        for (int i=arr.size()-1; i>=0; i--) {
            maxs = max(arr[i], maxs);
            result+= maxs - arr[i];
        }
        cout << result << '\n';
    }

    return 0;

}