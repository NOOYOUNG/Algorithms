import java.util.Stack;

class Solution {
    public int solution(String s) {
        Stack<Character> stack=new Stack<>();
        
        for(int i=0; i<s.length(); i++){
            if(!stack.isEmpty() && stack.peek()==s.charAt(i)){ // 스택의 peek 메서드를 사용하여 스택의 최상단 문자를 확인
                stack.pop(); // 중복된 문자 제거
            }
            else{
                stack.push(s.charAt(i)); // 스택에 문자 추가
            }
        }
        
        return stack.isEmpty()? 1 : 0;
        
        
        /*
        int answer = 0;
        StringBuffer str=new StringBuffer(s);
        
        for(int i=0; i<s.length()-1; i++){
            if(s.charAt(i)==s.charAt(i+1)){
                str.delete(i, i+2);
                i=0;
            }
        }
        
        if(str==null)
            answer=1;

        return answer;
        */
    }
}