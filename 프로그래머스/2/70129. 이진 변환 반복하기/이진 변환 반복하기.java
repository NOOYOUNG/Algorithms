class Solution {
    public int[] solution(String s) {
        int zero_cnt=0, cnt=0;
        
        while(!s.equals("1")){
            int len=s.length();
            s = s.replace("0","");
            cnt++;
            zero_cnt += (len-s.length());
            s = Integer.toBinaryString(s.length());
        }
        
        int[] answer={cnt, zero_cnt};        
        
        return answer;
    }
}