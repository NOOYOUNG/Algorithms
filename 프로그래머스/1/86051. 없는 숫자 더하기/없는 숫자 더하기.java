class Solution {
    public int solution(int[] numbers) {
        boolean[] pres=new boolean[10]; //모든 요소 false 초기화
        int sum=0;
        
        for(int num:numbers){
            pres[num]=true; //각 숫자 num에 대해 present[num]을 true로 설정
        }
        
        for(int i=0; i<10; i++){
            if(!pres[i]){
                sum+=i; //각 인덱스 i에 대해 present[i]가 false인 경우 합계에 i를 추가
            }
        }
        
        return sum;
    }
}