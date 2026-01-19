import java.util.*;
import java.io.*;

public class prog_javatest {
    static class Pair {
        int x;
        int y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }   

   public static void main(String[] args) throws Exception {
        // code
        System.out.println(" 0202002");
        String[] arr = {"apple","banana", "hi", "ㅕㅑㄴㅇㄹ", "ㅣsdfsdfㄴ아러", "100101"};
        String[] copys = Arrays.copyOf(arr, arr.length);
        String[] parts =Arrays.copyOfRange(arr, 2,4);
        for(String str: parts) {
            System.out.println(str + ",, ");
        }
        
        List<String> strs = new ArrayList<>(Arrays.asList(arr));
        
        Pair pairs = new Pair(1,2);
        ArrayList<Pair> pairss = new ArrayList<>();
        Collections.sort(strs, Collections.reverseOrder());
        pairss.add(new Pair(1,2));

        HashMap<Integer, String> hashMap = new HashMap<>();
        hashMap.put(1,"dd");
        hashMap.get(1);
        Integer[] nums = {1,2,3,4,5,6};
        Arrays.sort(nums, Collections.reverseOrder());
        for(Integer n: nums) {
            System.out.println(n +", ");
        }
        
        
    }
    
}