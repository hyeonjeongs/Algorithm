import java.util.*;
import java.io.*;

public class back_2599 {
     

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st= new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int [] num = new int[n];
        int [] dp = new int[n+1];

        for(int i=0; i<n; i++) {
            num[i] = Integer.parseInt(st.nextToken());
            
        }
        dp[0] = 0;
        for(int i=1; i<=n; i++) {
            dp[i] = dp[i-1] + num[i-1];
        }
        
        int maxNum = -1000;
        int sum= 0;

        for(int i=k; i<=n; i++) {
            sum = dp[i] - dp[i-k];
            maxNum = Math.max(maxNum, sum);
        }

        System.out.println(maxNum);

    }
}
