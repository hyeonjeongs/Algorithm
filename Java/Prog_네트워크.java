public class Prog_네트워크 {
    class Solution {
        boolean[] computer;
        void dfs(int[][] computers, int index, int n) {
            
            for(int i=0; i<n; i++) {
                if(index==i || computer[i]) {
                    continue;
                }
                if(computers[index][i] ==1) {
                    computer[i] = true;
                    dfs(computers, i, n);
                }
            }
        }
        
        public int solution(int n, int[][] computers) {
            int answer = 0;
            computer = new boolean[n];
            int cnt=0;
            for(int i=0; i<n; i++) {
                if(!computer[i]) {
                    computer[i] = true;
                    dfs(computers, i, n);
                    cnt= cnt+1;
                }  
            }
            answer = cnt;
            return answer;
        }
    }
}
