class Solution {
    public boolean solution(int x) {
        boolean answer = true;
        String s=Integer.toString(x);
        int len=s.length();
        char[] chars=s.toCharArray();
        int sum=0;
        
        for(int i=0; i<len; i++){
            sum+=s.charAt(i)-'0';
        }
        
        if(x%sum==0){
            answer=true;
        }
        else{
            answer=false;
        }
        
        return answer;
    }
}