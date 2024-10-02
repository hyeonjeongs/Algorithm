#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;
string calc(int front, int back, string order){
    if(order =="-") {
        return to_string(back-front);
    }
    if(order =="*") {
        return to_string(front*back);
    }
    if(order =="+"){
        return to_string(front+back);
    }

    return "";
}
long long solution(string expression) {
    long long answer = 0;
    queue<string> que;
    set<char> s;
    vector<string> order;

    string num = "";

    for(int i=0; i<expression.length(); i++) {
        char ch = expression[i];
        if(ch == '*' || ch=='-' || ch=='+') {
            s.insert(ch);
            que.push(num);
            string str(1,ch);
            que.push(str);
            num = "";
            continue;
        }
        num.push_back(ch);
    }
    que.push(num);


    for(char ch: s) {

        string str(1,ch);
        order.push_back(str);
    }

    cout << order[0] << order[1] << endl;

    queue<string> emptys;
    do {
        queue<string> new_que = que;
        queue<string> news;

        for(int i=0; i<order.size(); i++) {

            int back=0, front=0;
            news=emptys;

            while(!new_que.empty()) {

                if(new_que.front()==order[i]) { // 연산해야하는 경우

                    new_que.pop(); // 부호 pop
                    front = stoi(new_que.front());
                    news.push(calc(front, back, order[i]));
                    new_que.pop(); // 다음 숫자 pop
                    back = 0;
                    continue;
                }
                if(new_que.front()!="*" && new_que.front()!="-"&&new_que.front()!="+") {
                    back = stoi(new_que.front());
                    new_que.pop();
                    continue;
                }
                if(back!=0) {
                    news.push(to_string(back));
                    back = 0;
                }
                news.push(new_que.front());
                new_que.pop();
            }
            if(back !=0 ){
                news.push(to_string(back));
            }
            new_que = news;
            cout <<new_que.front() << " lkk "<<endl;

            if(new_que.empty()) {
                cout <<" sdfsdfsd "<<endl;
            }


        }
        if(!news.empty()) {
            long long result = abs(stoll(news.front()));
            answer = max(answer, result);
        }

    } while(next_permutation(order.begin(), order.end()));

    return answer;
}