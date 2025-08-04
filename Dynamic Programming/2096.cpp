#include <iostream>
#include <vector>
using namespace std;

int mins[3] = {0,};
int maxs[3] {0,};
int input[3] = {0,};

int main() {
    int n;
    cin >> n;

    cin >> mins[0] >> mins[1] >> mins[2];
    maxs[0] = mins[0];
    maxs[1] = mins[1];
    maxs[2] = mins[2];

    for(int i=1; i<n; i++) {
        cin >> input[0] >> input[1] >> input[2];
        int tmp1 = mins[0];
        int tmp2= mins[1];
        int tmp3 = mins[2];
        mins[0] = min(tmp1, tmp2) + input[0];
        mins[1] = min(tmp1, min(tmp2, tmp3)) + input[1];
        mins[2] = min(tmp2, tmp3) + input[2];

        tmp1 = maxs[0];
        tmp2 = maxs[1];
        tmp3 = maxs[2];
        maxs[0] = max(tmp1, tmp2) + input[0];
        maxs[1] = max(tmp1, max(tmp2, tmp3)) + input[1];
        maxs[2] = max(tmp2, tmp3) + input[2];
    }


    int result_max = max(maxs[0], max(maxs[1], maxs[2]));
    int result_min = min(mins[0], min(mins[1], mins[2]));
    cout << result_max << " " << result_min << '\n';

    return 0;

}