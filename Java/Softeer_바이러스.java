import java.io.*;
import java.util.*;

public class Main {

    
    public static void main(String[] args) throws IOException {
        int NUM = 1000000007;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());
        long result = k;
        
        for(int i=0; i<n; i++) {
            result = (result * p)%NUM;
        }
        
        System.out.println(result);
    }
}