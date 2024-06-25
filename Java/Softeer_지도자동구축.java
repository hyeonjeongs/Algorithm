import java.io.*;
import java.util.*;

public class Softeer_지도자동구축 {

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int num=2;
        for(int i=0;i <n; i++) {
            num = num*2 -1;
        }
        System.out.println(num*num);
    }
}
