import java.util.ArrayList;
import java.util.Collections;

class Solution {
    public int[] solution(int[] arr, int divisor) {
        ArrayList<Integer> answerList=new ArrayList<Integer>();
        
        for(int num:arr){
            if(num%divisor==0){
                answerList.add(num);
            }
        }
        
        Collections.sort(answerList);
        
        int[] answer;
        if(answerList.isEmpty()){
            answer=new int[]{-1};
        }
        else{
            answer=new int[answerList.size()];
            for(int i=0; i<answerList.size(); i++){
                answer[i]=answerList.get(i);
            }
        }
        
        
        return answer;
    }
}