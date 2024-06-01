class Solution {
    public String solution(String phone_number) {
        int len=phone_number.length();
        StringBuilder answer=new StringBuilder();
        
        for(int i=0; i<len-4; i++){
            answer.append("*");
        }
        
        answer.append(phone_number.substring(len-4)); //substring(int index) 주어진 index부터 시작하는 부분 문자열 반환
        
        return answer.toString();
    }
}