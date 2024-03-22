#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int li = 0, ri = 0;
    int min_size = sequence.size() +1;
    int sum = sequence[0];
    answer.assign(2,0);

    while(li <= ri && ri < sequence.size()) {

        if(sum < k) {
            sum += sequence[++ri];
        }
        else if(sum == k) {
            if(min_size > ri-li+1) {
                answer[0] = li;
                answer[1] = ri;
                min_size = ri - li +1;
            }
            if(min_size == ri-li+1 && li<answer[0]) {
                answer[0] = li;
                answer[1] = ri;
            }
            sum -= sequence[li++];
        } else {
            sum -= sequence[li++];
        }
    }

    return answer;
}