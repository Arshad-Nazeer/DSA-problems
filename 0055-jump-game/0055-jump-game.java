class Solution {
    // boolean recur(int[] nums, int k){
    //     if(k==nums.length-1) return true;
    //     else if(k>=nums.length) return false;
    //     // for(int i=1; i<nums.length-k && i<=nums[k]; i++){
    //     //     if(recur(nums, k+i)) return true;
    //     // }
    //     for(int i=Math.min(nums.length-1-k, nums[k]); i>=1; i--){
    //         if(recur(nums, k+i)) return true;
    //     }
    //     return false;
    // }

    public boolean canJump(int[] nums) {
        // backtracking TC:- exponential
        // return recur(nums, 0);

        // int n=nums.length, greedyIndex=nums.length-1;
        // for(int i=n-2; i>=0; i--){
        //     if(i+nums[i]>=greedyIndex) greedyIndex=i;
        // }
        // return greedyIndex==0;

        int n=nums.length, greedyIndex=0;
        for(int i=0; i<nums.length; i++){
            if(i>greedyIndex) return false;
            // if(i+nums[i]>greedyIndex) greedyIndex=i+nums[i];
            greedyIndex=Math.max(i+nums[i], greedyIndex);
        }
        return greedyIndex>=nums.length-1;
    }
}