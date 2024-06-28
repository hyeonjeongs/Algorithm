import java.io.*;
import java.util.*;

public class Softeer_순서대로방문 {
    static int[] dr = {0,1,0,-1};
    static int[] dc = {1,0,-1,0};
    static int m;
    static int n;
    static int[][] check;
    static int[][] arr;
    static int result=0;
    static boolean[][] visited;
    
    public static void dfs(int r, int c, int cnt) {
        
        if(check[r][c]==cnt) {
            if(cnt==m-1) {
                result +=1;
                return;
            }
            cnt+=1;
        } 
        
        visited[r][c] = true;
        for(int i=0; i<4; i++) {
            int new_r = r + dr[i];
            int new_c = c + dc[i];
            if(new_r<0 || new_c<0 || new_r >=n || new_c>=n || visited[new_r][new_c]) {
                continue;
            }
            if(arr[new_r][new_c]==1){
                continue;
            }
            
            dfs(new_r, new_c, cnt);
            
        }
        visited[r][c] = false;
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[n][n];
        check = new int[n][n];
        int[][] go = new int[m][2]; // 행, 열
        
        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for(int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            go[i][0] = Integer.parseInt(st.nextToken())-1;
            go[i][1] = Integer.parseInt(st.nextToken())-1;
            check[go[i][0]][go[i][1]] = i;
            
            
        }
        visited = new boolean[n][n];
        
        visited[go[0][0]][go[0][1]] = true;
        dfs(go[0][0], go[0][1], 1);
      
        System.out.println(result);
    }
}
