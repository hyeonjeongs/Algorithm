
import java.io.*;
import java.util.*;

public class Softeer_근무시간 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int time =0;
        for(int i=0; i<5; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String start = st.nextToken();
            String end = st.nextToken();
            String[] startArr = start.split(":");
            String[] endArr = end.split(":");
            
            time = time + (Integer.parseInt(endArr[0]) - Integer.parseInt(startArr[0]))*60 
                + (Integer.parseInt(endArr[1]) - Integer.parseInt(startArr[1]));
            
        }
        System.out.println(time);
    }
    
}
