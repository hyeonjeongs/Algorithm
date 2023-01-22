#include <iostream>
#include <vector>
#include <string>

using namespace std;

int makMaxNum(string N, char x, char y){

    int max_num = max(x, y);
    int min_num = min(x,y);

    string max_string = N;
   for(int i=0; i<N.size(); i++){
       max_string[i] = max_num;

       if(stoi(N) < stoi(max_string) ){
           max_string[i] = min_num;
       }
       if(max_string[0] == '0'){
           max_string[0] = max_num;
       }
   }
   if(stoi(N) < stoi(max_string)){
       return -1;
   }

   return stoi(max_string);
}

int main(){
    int t;
    cin>>t;
    string N;
    char x, y;
    for(int i=0; i<t; i++){

        cin>> N >> x >> y;
        cout << makMaxNum(N,x,y)<<'\n';
    }
}