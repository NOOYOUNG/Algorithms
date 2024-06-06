import java.util.*;
class Solution {
    public int solution(int[] arr) {
        Arrays.sort(arr);
        
        for(int i=0; i<arr.length-1; i++){
            int num=gcd(arr[i+1], arr[i]); //최대공약수 구하기
            arr[i+1]=(arr[i]*arr[i+1])/num; // 두수의 곱=최대공약수X최소공배수
        }
        
        return arr[arr.length-1];
    }
    
    public static int gcd(int a, int b) {
        if(a%b==0) // 약수 구하기
            return b;
        
        return gcd(b, a%b);
    }
}