#include <string>
#include <vector>

using namespace std;

string makeString(int n, int num) {
    string a[] = {"0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"};
    if(num < n) {
        return a[num];
    }
    else{
        return makeString(n, num/n) + a[num%n];
    }
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string numbers = "";

    for(int i=0; i<=t*m; i++) {
        numbers += makeString(n, i);
    }
    for(int i=0; i<=numbers.length(); i++) {
        if(i%m == p-1) {
            answer+= numbers[i];
        }
        if(answer.length() == t) {
            break;
        }
    }

    return answer;
}