#include <string>
#include <vector>

using namespace std;

int result =0;
vector<bool> visited;
vector<int> nums;
void addNumber(int index, int target) {
    int num=0;
    for(int i=0;i <nums.size(); i++) {
        num += nums[i];
    }
    if(num == target) {
        result++;
        return;
    }

    for(int i = index; i<nums.size();i++) {
        if(visited[i]) {
            continue;
        }
        visited[i] = true;
        nums[i] = -num[i];
        addNumber(i+1, target);
        visited[i] = false;
        nums[i] = -num[i];
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    visited.assign(numbers.size(), 0);
    nums = numbers;

    for(int i=0; i<numbers.size(); i++) {
        nums[i] = -num[i];
        addNumber(i+1,target);
        nums[i] = -num[i];
    }



    return answer;
}