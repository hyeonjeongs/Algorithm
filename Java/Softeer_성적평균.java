import java.io.*;
import java.util.*;

public class Main {
    static List<Integer> dp = new ArrayList<>();

    public static void makeAvg(int left, int right) {
        double num = (double)(dp.get(right) - dp.get(left-1))/(double)(right-left+1);
        num = Math.round(num*100)/100.0;
        System.out.println(num);
    }

    public static void main(String[] args) throws IOException{
        int n, k;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        
        String[] input = br.readLine().split(" "); // 성적
        dp.add(0);
        for(int i=1; i<=n; i++) {
            dp.add(Integer.parseInt(input[i-1]) + dp.get(i-1));
        }
        
        for(int i=0; i<k; i++) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken());
            int right = Integer.parseInt(st.nextToken());
            makeAvg(left, right);
        }

        
    }
}