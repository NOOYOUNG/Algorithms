class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int sum=0;
        for(int i=0; i<absolutes.length; i++){
            if(signs[i]==false){
                absolutes[i]=-1*absolutes[i];
            }
            else{
                absolutes[i]=absolutes[i];
            }
            sum+=absolutes[i];
        }
        
        return sum;
    }
}