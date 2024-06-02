import java.util.ArrayList;
class Solution {
    public String solution(String s) {
        String[] N=s.split(" "); 
        ArrayList<String> nums=new ArrayList<String>();
        for(String str:N){
            if(!str.isEmpty()){
                nums.add(str);
            }
        }
        
        int max=Integer.parseInt(nums.get(0));
        int min=Integer.parseInt(nums.get(0));
        
        for(String str:nums){
            int number=Integer.parseInt(str);
            
            if(max<number)
                max=number;
            if(min>number)
                min=number;
        }
        
        return min+" "+max;
    }
}