#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> nums;
vector<bool> check;
void backTracking(int index){

    // 가지치기
    if(index == m){
        for(int i=0; i<nums.size(); i++){
            cout<< nums[i] << " ";
        }
        cout << '\n';
        
        return;
    }

    for(int i=1; i<=n; i++){
        nums[index] = i;
        backTracking(index+1);
    }

}

int main() {

    cin >> n >> m;

    nums.assign(m,0);
    check.assign(n+1, false);

    backTracking(0);

    return 0;
}