import java.io.*;
import java.util.*;

public class Main {
    public static int[] visited1 = new int[100001];
    public static int[] visited2 = new int[100001];
    public static List<List<Integer>> nums= new ArrayList<>();
    
        public static boolean dfs2(int current, int end, int n) {
        if(nums.get(current).size()<0 && current!=end)
            return false;
        boolean flag=false;
        for(int i=0; i<nums.get(current).size(); i++) {
            int next = nums.get(current).get(i);
            if(next==end) {
                flag=true;
                continue;
            }
            if(visited2[next]==1) {
                flag = true;
                continue;
            }
            visited2[next] = 1;
            if(!dfs2(next, end, n)) {
                visited2[next]=0;
            }
            else {
                flag = true;
            }
        }
        return flag;
    }
    public static boolean dfs1(int current, int end, int n) {
        if(nums.get(current).size()<0 && current!=end)
            return false;
        boolean flag=false;
        for(int i=0; i<nums.get(current).size(); i++) {
            int next = nums.get(current).get(i);
            if(next==end) {
                flag=true;
                continue;
            }
            if(visited1[next]==1) {
                flag = true;
                continue;
            }
            visited1[next] = 1;
            if(!dfs1(next, end, n)) {
                visited1[next]=0;
            }
            else {
                flag = true;
            }
        }
        return flag;
    }
    public static int check(int n, int s, int t) {
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            if(i==s || i==t) {
                continue;
            }
            if(visited1[i] ==1 && visited2[i] ==1) {
                cnt+=1;
            }
        }
        return cnt;
    }
    
    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
    
        
        for(int i=0; i<=n; i++) {
            nums.add(new ArrayList<>());
        }
        for(int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            nums.get(x).add(y);
        }
        st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        visited1[s] = 1;visited1[t] = 1;
        visited2[s] = 1;visited2[t] = 1;
        
        dfs1(s,t,n); 
        dfs2(t,s,n); 
        int cnt = check(n,s,t);
        System.out.println(cnt);
        
    }
}
