#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int index = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(int i=0; i<A.size(); i++) {
        int num = A[i];
        while(1) {
            if(index>=B.size()){
                break;
            }
            if(B[index]>num){
                answer++;
                index++;
                break;
            }
            index++;
        }
    }

    return answer;
}