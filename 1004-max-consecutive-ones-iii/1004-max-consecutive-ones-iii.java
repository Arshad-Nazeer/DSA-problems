class Solution {
    public int longestOnes(int[] nums, int k) {
        int left=0, right=0, count=0, ans=0;
        while(right<nums.length){
            if(nums[right]==1) right++;
            else if(k>0) {
                right++;
                k--;
            }else{
                while(nums[left]!=0) left++;
                left++;
                k++;
            }
            ans=Math.max(ans, right-left);
        }    
        return ans;   
    }
}