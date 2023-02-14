#include <iostream>
#include <vector>

/*
 * 좀더 고민
 */

using namespace std;
// 최소한의 예산이 들 높이를 구하자 -> 높이가 h일때 m개의 가로등이 설치가 가능한가

int lightSet(int height, vector<int> lightLocation, int n){
    vector<int> light(n, 0);

    // 처음
    if(lightLocation[0]>height){
        return 0;
    }

    for(int i=1; i<lightLocation.size(); i++){
        if(lightLocation[i] - lightLocation[i-1] >height*2){
            return 0;
        }
    }

    if(n-lightLocation[lightLocation.size()-1] > height){
        return 0;
    }

    return 1;
}

int binarySearch(vector<int> lightLocation, int low, int high){
    int n = high;
    int result = 1;
    while(low <= high){
        int mid= (low + high)/2;
        int num = lightSet(mid, lightLocation, n);

        if(num == 1){
            result = mid;
            high = mid -1;
        }else{
            low = mid +1;
        }
    }
    return result;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin>> n>>m;
    vector<int> lightLocation(m, 0);

    for(int i=0 ; i<m; i++){
        cin>> lightLocation[i];
    }

    cout<<binarySearch(lightLocation, 0, n)<<'\n';

    return 0;
}