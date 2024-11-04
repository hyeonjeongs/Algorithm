import java.io.*;
import java.util.*;


public class back_2806 {
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int[] arr = new int[n+1];

        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int dist = 1000000;
        int sum = arr[0];
        int li=0, ri=0;
        while(li<=ri && ri<n) {

            if(sum >=s) {
                dist = Math.min(dist, ri-li+1);
                sum = sum - arr[li];
                li= li+1;
            } else {
                ri = ri+1;
                sum = sum+ arr[ri];
            }
        }

        if(dist == 1000000){
            dist = 0;
        }

        System.out.println(dist);
    }
}
