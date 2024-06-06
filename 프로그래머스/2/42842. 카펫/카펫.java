class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        
        for(int h=1; h<=(int)Math.sqrt(yellow); h++){
            if(yellow%h==0){
                int w=yellow/h;
                
                if(brown==2*(w+h)+4){
                    answer[0]=w+2;
                    answer[1]=h+2;
                }
            }
        }
        
        return answer;
    }
}