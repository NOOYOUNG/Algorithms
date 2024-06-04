class Solution {
    public int solution(int n) {
        int answer = 0;
        int cnt=1;
        n-=cnt;
        
        while(n>0){
            cnt++;
            n=n-cnt;
            if(n%cnt==0)
                answer++;
        }
        return answer+1;
    }
}