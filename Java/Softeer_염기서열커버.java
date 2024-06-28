import java.io.*;
import java.util.*;

public class Main {
    public static List<String> str = new ArrayList<>();

    public static void cmpStr(String input, int m) {
        boolean isPossible = false;
        boolean isNew = false;
        int j=0;
        for(int i=0; i<str.size(); i++) {
            String current = str.get(i);
            
            for(j=0; j<m; j++) {
                
                if(current.charAt(j) == '.' || input.charAt(j)=='.') {
                    if(current.charAt(j)!=current.charAt(j)) {
                        isNew = true;
                    }
                    continue;
                }
                if(input.charAt(j) != current.charAt(j)) {
                    break;
                }
            }
            
            if(j==m) {
                if(isNew) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(current);
                    for(int k=0; k<m; k++) {
                        if(current.charAt(k) != input.charAt(k)) {
                            if(current.charAt(k)=='.') {
                                sb.setCharAt(k, input.charAt(k));
                            }
                            else if(input.charAt(k)=='.') {
                                sb.setCharAt(k, current.charAt(k));
                            }
                        }
                    }
                    str.set(i, sb.toString());
                }
                isPossible = true;
                break;
            }
        }
        if(!isPossible){
            str.add(input);
        }
    }
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        str.add(br.readLine());
        
        for(int i=1; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            String input = st.nextToken();
            cmpStr(input, m);
        }
        System.out.println(str.size());
    }
}
