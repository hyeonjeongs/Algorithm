class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        int total = brown + yellow;
        int i;
        for(i=3; i<=total/2;i++) {
            if(total%i !=0) {
                continue;
            }
            int height = i;
            int width = total/i;
            if((width-2)*(height-2) == yellow) {
                break;
            }
        }
        answer[1] = i; answer[0] = total/i;
        return answer;
    }
}