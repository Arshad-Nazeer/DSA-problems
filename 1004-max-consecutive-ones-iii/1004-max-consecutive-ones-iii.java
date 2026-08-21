class Solution {
    public int longestOnes(int[] nums, int k) {
        // int left=0, right=0, count=0, ans=0;
        // while(right<nums.length){
        //     if(nums[right]==1) right++;
        //     else if(k>0) {
        //         right++;
        //         k--;
        //     }else{
        //         while(nums[left]!=0) left++;
        //         left++;
        //         k++;
        //     }
        //     ans=Math.max(ans, right-left);
        // }    
        // return ans;   

        int left=0, zeroes=0, ans=0;
        for(int right=0; right<nums.length; right++){
            if(nums[right]==0) zeroes++;
            while(zeroes>k){
                if(nums[left]==0) zeroes--;
                left++;
            }
            ans=Math.max(right-left+1, ans);
        }
        return ans;
    }
}