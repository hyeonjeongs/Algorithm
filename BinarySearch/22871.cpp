#include <iostream>
#include <vector>

using namespace std;
vector<int> stone;
int n;
void minStone(int left, int right) {


    while(left<right){
        int k = (left+right)/2;

    }

}

int main() {

    cin>> n;
    stone.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>stone[i];
    }

    minStone(0,n);

}