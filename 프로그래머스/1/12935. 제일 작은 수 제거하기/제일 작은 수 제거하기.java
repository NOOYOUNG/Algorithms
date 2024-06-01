class Solution {
    public int[] solution(int[] arr) {
        int[] answer;
        int len=arr.length;
        int least=0;
        
        if(len==1){
            answer=new int[]{-1};
        }
        
        for(int i=1; i<len; i++){
            if(arr[i]<arr[least])
                least=i;
        }
            
        answer=new int[len-1];
        
        int j=0;
        for(int i=0; i<len; i++){
            if(i!=least)
                answer[j++]=arr[i];
        }
        
        return answer;
    }
}