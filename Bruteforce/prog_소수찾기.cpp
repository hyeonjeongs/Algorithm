#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

bool isPrime(int num) {
    if(num<2) {
        return false;
    }

    for(int i=2; i<=sqrt(num);i++) {
        if(num%i ==0) {
            return false;
        }
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> result;

    sort(numbers.begin(), numbers.end());

    do{
        string ans;
        for(int i=0; i<numbers.size(); i++) {
            ans+=numbers[i];
            if(isPrime(stoi(ans))) {
                result.insert(stoi(ans));
            }
        }

    }while(next_permutation(numbers.begin(), numbers.end()));
    answer = result.size();

    return answer;
}