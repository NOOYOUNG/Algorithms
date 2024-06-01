import java.util.ArrayList;
class Solution {
    public int solution(int n) {
        int answer = 0;
        ArrayList<Integer> divisors=new ArrayList<Integer>();
        
        for(int i=1; i<=n; i++){
            if(n%i==0){
                divisors.add(i);
            }
        }
        
        for(int divisor:divisors){
            answer+=divisor;
        }
        
        return answer;
    }
}