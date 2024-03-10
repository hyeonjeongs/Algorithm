#include <iostream>
#include <vector>

using namespace std;

int desSum(int n){
    int min_sum=1e6;

    int i;
    
    for(i=n-1; i>0; i--){
        int sum = 0; // 분해합 전체 합
        string n_str = to_string(i); // 숫자 i를 string으로 숫자로 바꿔줌

        int n_size = n_str.size(); // n의 자리수

        sum += i;
        for(int j=0; j<n_size; j++){
            sum += n_str[j] - '0';
        }

        if(sum == n){
            min_sum = min(i, min_sum);
        }
    }
    if(min_sum==1e6){
        return 0;
    }

    return min_sum;
}

int main(){
    int n;

    cin>> n; //분해합
    cout<<desSum(n)<<'\n';
    return 0;
}