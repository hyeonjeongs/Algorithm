#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, c;
vector<int> location;

int checkRouter(int dist) {
    int cnt =1;
    int index =0;
    for (int i=1; i<location.size(); i++) {
        int current = location[i] - location[index];
        if (current>=dist) {
            cnt++;
            index = i;
        }
    }
    return cnt;
}

int checkDist(int left, int right) {

    int result = 0;
    while (left <=right) {
        int mid = (left + right)/2;
        int routers = checkRouter(mid);

        if (routers>=c) {
            left = mid+1;
            result = max(mid, result);
        } else if (routers <c){
            right = mid-1;
        }
    }
    return result;
}

int main() {
    cin >> n >> c;
    location.assign(n, 0);
    for (int i=0; i<n; i++) {
        cin >> location[i];
    }
    sort(location.begin(), location.end());

    cout << checkDist(1, location[location.size()-1]- location[0]);
    return 0;
}