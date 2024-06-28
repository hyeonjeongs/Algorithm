import java.io.*;
import java.util.*;

public class Softeer_성적평가 {

    public static void rankPrint(int[] scores, int n) {
        
        int[] score_copy = Arrays.copyOf(scores, n);
        Integer[] score = Arrays.stream(scores).boxed().toArray(Integer[]::new);
        
        Arrays.sort(scores);
      
        for(int i=0; i<n; i++) {
            int ranks = Arrays.binarySearch(scores, score_copy[i]);
            int j= ranks+1;
            while(true){
                if(j>=n) {
                    j-=1;
                    break;
                }
                if(scores[j]==scores[ranks] ) {
                    j+=1;
                } else{
                    j-=1;
                    break;
                }
            }
            
            System.out.print(n-j + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] total = new int[n];
        
        for(int i=0; i<3; i++) {
            int[] score = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++) {
                int num = Integer.parseInt(st.nextToken());
                score[j] = num;
                total[j]+=num;
            }
            rankPrint(score, n);
        }
        rankPrint(total, n);
    }
}
