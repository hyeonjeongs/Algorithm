public class Prog_타겟넘버 {

    class Solution {
        int[] number;
    
        int size;
        int ans =0;
        
        public void dfs(int target, int index, int[] num) {
            if(index==size) {
                int result=0;
                for(int i=0; i<size; i++) {
                    result += num[i];
                }
                if(result == target) {
                    ans = ans +1;
                }
                return;
            }
        
            num[index] = number[index];
            dfs(target, index+1,num);
            
            num[index] = -number[index];
            dfs(target, index+1,num);
    
        }
        
        
        public int solution(int[] numbers, int target) {
            int answer = 0;
            number = numbers;
            size = numbers.length;
    
            int[] nums = new int[size];
            
            dfs(target, 0, nums);
            answer = ans;
            return answer;
        }
    }
}
