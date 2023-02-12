#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void inverseWord(vector<char> str){
    stack<char> st;

    for(int i=0; i<str.size(); i++){

        if(st.empty()){
            st.push(str[i]);
            if(str[i] == '<'){
                cout<<'<';
            }
            continue;
        }

        //태크인 경우
        if(st.top()=='<'){
            if(str[i] == '>'){
                st.pop();
                cout<< '>';
            } else{
                cout<<str[i];
            }
            continue;
        }

        // 반대 숫자 출력하기
        if(str[i]==' ' || str[i] =='<'){
            // 스택에 넣은 단어 출력

            while(!st.empty()){
                cout<< st.top();
                st.pop();
            }

            if(str[i] == ' '){
                cout<< ' ';
            }
            if(str[i] == '<'){
                st.push(str[i]);
                cout<< '<';
            }

            continue;
        }

        //마지막인 경우
        if(i==str.size()-1){
            st.push(str[i]);
            while(!st.empty()){
                cout<< st.top();
                st.pop();
            }
        }

        st.push(str[i]);
    }
}

int main(){
    vector<char> str;

    while(true){
        char input;
        cin.get(input);
        if(input == '\n'){
            break;
        }
        str.push_back(input);
    }

    inverseWord(str);

    return 0;

}