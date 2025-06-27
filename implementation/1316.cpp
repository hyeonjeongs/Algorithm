#include <iostream>
#include <vector>

using namespace std;


int wordChecker(string word, vector<int> alpha){
    alpha[(int)word[0]-97] = 1;

    for(int i=1; i<word.size(); i++){
        if(alpha[(int)word[i]-97]==0){ // = [word[i] - 'a']
            alpha[(int)word[i]-97] = 1;
            continue;
        }
        if(word[i-1]==word[i]){
            continue;
        }
        return 0;
    }
    
    return 1;
}

int main(){
    int n;
    int result =0, cnt=0;
    cin >>n;
    vector<int> alpha(26,0);

    for(int i=0; i<n; i++){
        string input;
        cin>> input;
        result = wordChecker(input,alpha);

        if(result == 1){
            cnt++;
        }
    }
    cout<< cnt;

    return 0;
}
