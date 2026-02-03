import java.io.*;
import java.util.*;

class LiveCoding {
    public void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        List<Integer> list = new ArrayList<>();
        int[] arr = list.stream()
            .mapToInt(Integer::intValue)
            .toArray();

    }
}