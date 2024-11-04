import java.io.*;
import java.util.*;

public class prog_20002 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int n = Integer.parseInt(br.readLine());

        int[][] trees = new int[n+1][n+1];
        int[][] sums = new int[n+1][n+1];

        for(int i=1; i<=n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++) {
                trees[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++){
                sums[i][j] = trees[i][j] + sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1];
            }
        }

        int total = -1001;

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                int sizes = Math.min(n-i, n-j);
                for(int k=0; k<=sizes; k++) {
                    int num = sums[i+k][j+k] - sums[i+k][j-1] - sums[i-1][j+k] + sums[i-1][j-1];
                    total = Math.max(total, num);
                }
            }
        }
        System.out.println(total);
    }
}
