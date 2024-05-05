import java.util.*;

public class Prog_여행경로 {
    
    class Solution {
        boolean[][] visited;
        
        int size;
        List<List<Integer>> result = new ArrayList<>();
        
        public void dfs(int index, int[] arr, int cnt, boolean [][] number) {
            if(cnt>=size) {
                Integer[] addList = new Integer[arr.length];
                for(int i=0; i<arr.length; i++) {
                    addList[i] = Integer.valueOf(arr[i]);
                }
                result.add(Arrays.asList(addList));
                return;
            }
            
            for(int i=0; i<size; i++) {
                if(!visited[index][i]|| !number[index][i]){
                    continue;
                }
                arr[cnt+1] = i;
                visited[index][i] = false;
                dfs(i, arr, cnt+1, number);
                arr[cnt+1] = -1;
                visited[index][i] = true;
            }
        }
        
        public String[] solution(String[][] tickets) {
            String[] answer = {};
            Map<Integer, String> int_str = new HashMap<>();
            Map<String, Integer> str_int = new HashMap<>();
            List<String> str = new ArrayList<>();
            int[][] int_ticket = new int[tickets.length][2];
            
            size = tickets.length;
            
            int cnt=1;
            
            
            for(int i=0; i<tickets.length; i++) {
                for(int j=0; j<2; j++) {
                    if(str.equals("ICN") || str.contains(tickets[i][j])) {
                        continue;
                    }
                    str.add(tickets[i][j]);
                    cnt= cnt+1;
                }
            }
            Collections.sort(str);
            str.add(0,"ICN");
            
            int_str.put(0,"ICN");
            str_int.put("ICN",0);
            
            
            for(int i=1; i<str.size(); i++) { // map에 저장하기
                int_str.put(i, str.get(i));
                str_int.put(str.get(i), i);
            }
            
            boolean [][] number = new boolean[str.size()][str.size()];
            visited = number;
            for(int i=0; i<tickets.length; i++){
                number[str_int.get(tickets[i][0])][str_int.get(tickets[i][1])] = true;
            }
            
            int[] arr = new int[size*2];
            Arrays.fill(arr, -1);
            arr[0] = 0;
            
            for(int i=0; i<size; i++) {
                if(number[0][i]) {
                    visited[0][i] = false;
                    dfs(i, arr, 0, number);
                    visited[0][i] = true;
                }
                
            }
            List<String> strs = new ArrayList<>();
            for(int i=0; i<result.get(0).size(); i++) {
                if(result.get(0).get(i)>=0){
                    strs.add(int_str.get(i));
                }
            }
            answer = strs.toArray(new String[str.size()]);
            return answer;
        }
    }
}
