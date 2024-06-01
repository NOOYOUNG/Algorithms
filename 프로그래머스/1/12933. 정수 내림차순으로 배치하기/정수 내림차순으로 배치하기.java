import java.util.Arrays;

class Solution {
    public long solution(long n) {
        long answer = 0;
        String s=Long.toString(n);
        char[] chars=s.toCharArray();
        
        Arrays.sort(chars);
        StringBuilder sorted=new StringBuilder(new String(chars));
        sorted.reverse();
        
        answer=Long.parseLong(sorted.toString());
        
        return answer;
    }
}