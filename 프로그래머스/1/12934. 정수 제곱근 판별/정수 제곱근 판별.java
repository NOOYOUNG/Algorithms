class Solution {
    public long solution(long n) {
        long x=(long)Math.sqrt(n);
        
        if(x>0 && (x*x==n)){
            return (x+1)*(x+1);
        }
        else{
            return -1;
        }
    }
}