#include<iostream>
#include<vector>

using namespace std;

int endNum(int n){
    int cnt=0;
    for(int i=666;; i++){
        int num = i;

        while(num>=666){
            if(num%1000 == 666){
                cnt++;
                break;
            }
            num/=10;
        }

        if(cnt==n){
            return i;
        }
    }
}

int main(){
    int n;
    cin>>n;

    cout<<endNum(n)<<'\n';

    return 0;
}