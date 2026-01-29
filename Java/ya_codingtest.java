import java.util.*;

class Solution {

    long calc(int start, int end, char[] ops, long[] nums) {

        long current = nums[start];
        long[] tmpNums = new long[end - start + 1];
        char[] tmpOps = new char[end- start + 1];
        int ni=0, oi = 0;

        for(int i=start; i<=end; i++) {
            char op = ops[i];
            if(op == 'x') {
                current *= nums[i+1];
            } else {
                tmpNums[ni++] = current;
                tmpOps[oi++] = op;
                current = nums[i+1];
            }

        }
        long result = tmpNums[0];

        for(int i=0; i<tmpOps.length; i++) {
            char op = tmpOps[i];
            if(op == '+') {
                result += tmpNums[i+1];
            } else {
                result -= tmpNums[i+1];
            }
        }
        return result;
    }
    public long solution(String expression) {
        long result =0;
        long numbers[] = new long[102];
        char ops[] = new char[102];
        int numIndex =0, opsIndex = 0;

        for(int i=0; i<expression.length(); i++) {
            char c = expression.charAt(i);
            if(c >='0' && c<='9') {
                numbers[numIndex++] = (long)(c-'0');
            } else {
                ops[opsIndex++] = c;
            }
        }
        int n = opsIndex;

        for(int i=0; i<n; i++) {

            for(int j=i; j<n; j++) {
                
                long mid = (i==j) ? numbers[i] : calc(i, j-1, ops, numbers);

                int newNums = n - (j- i);
                long newNum[] = new long[newNums];
                char newOps[] = new char[newNums-1];
                int[] map = new int[n];
                Arrays.fill(map, -1);

                int idx =0;
                for(int k=0; k<i; k++) {
                    if(k==i) {
                        newNum[idx] = mid;
                        for(int l=i; l<j; l++) {
                            map[l] =idx;
                        }
                        idx++;
                        k = j;
                    } else {
                        newNum[idx] = numbers[k];
                        map[k] = idx;
                        idx++;
                    }

                }

                for(int m=0; m<n-1;m++) {
                    int current = map[m];
                    int next = map[m+1];
                    if(current != -1 && next!=-1 && current !=next) {
                        newOps[current] = ops[m];
                    }
                }

                long val = (newOps.length==0)? newNum[0] : calc(0, newOps.length-1, newOps, newNum);
                result = Math.max(result, val);
            }
        }



        return result;
    }

}