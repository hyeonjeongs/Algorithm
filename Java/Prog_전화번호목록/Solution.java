import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Map<String, Integer> phone = new HashMap<>();
        
        for(int i=0; i<phone_book.length; i++) {
            phone.put(phone_book[i], i);
        }
        
        for(int i=0; i<phone_book.length; i++) {
            StringBuilder sb = new StringBuilder();
            for(int j=0; j<phone_book[i].length(); j++) {
                sb.append(phone_book[i].charAt(j));
              
                if(phone.containsKey(sb.toString()) && phone.get(sb.toString()) !=i) {
                    return false;
                }
            }
        }
        return answer;
    }
}