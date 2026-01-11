#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
    int start;
    int end;
    int dist;
    bool operator<(const Node& other) const {
        if (end == other.end) {
            return start < other.start;
        }
        return end < other.end;
    }
};
int main() {
    int n, d;
    cin >> n>> d;
    vector<int> dp(d+1, 0);
    fill(dp.begin(), dp.end(), 1e5);

    vector<Node> arr;


    for (int i=0; i<n ;i++) {
        int start, end, dist;
        cin >> start >> end >> dist;
        arr.push_back({start, end, dist});
    }
    sort(arr.begin(), arr.end());

    int index =0;
    dp[0] = 0;
    for (int i=1;i<=d; i++) {
        while (index<n) {
            Node nodes = arr[index];
            if (i != nodes.end) {
                break;
            }
            if (i == nodes.end){
                index++;
                dp[i] = min(dp[i], nodes.dist + dp[nodes.start]);
            }
        }
        dp[i] = min(dp[i-1]+1, dp[i]);
    }

    cout << dp[d]<< endl;
    return 0;
}