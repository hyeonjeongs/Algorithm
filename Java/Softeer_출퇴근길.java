import java.io.*;
import java.util.*;

public class Main {
    
    public static int bfs(int s, int t, int n, boolean[][] node) {
        int[] visited = new int[n+1]; // 초기는 0, 지나가면1, 체크하면 음수
        int cnt = 0;
        Queue<Integer> que = new LinkedList<>();
        que.add(s);
        while(!que.isEmpty()) {
            int num = que.peek();
            que.poll();
            
            for(int i=1; i<=n; i++) {
                if(i==t) {
                    continue;
                }
                if(node[num][i] && visited[i]!=1) {
                    que.add(i);
                    visited[i] = 1;
                }
            }
        }
        
        que.add(t);
        while(!que.isEmpty()) {
            int num = que.peek();
            que.poll();
            for(int i=1; i<=n; i++) {
                if(i==s) {
                    continue;
                }
                if(node[num][i]) {
                    que.add(i);
                    if(visited[i]==1) {
                        cnt++;
                        visited[i]=-1;
                    }
                }
            }
        }
        return cnt;
    }
    
    public static void main(String[] args) throws IOException{
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        boolean[][] node = new boolean[n+1][n+1];

        for(int i=0; i<m; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            node[x][y]=true;

        }
        st = new StringTokenizer(br.readLine());
        int s = Integer.parseInt(st.nextToken());
        int t = Integer.parseInt(st.nextToken());
        
        int result = bfs(s,t,n, node);
        System.out.println(result);
    }
}
