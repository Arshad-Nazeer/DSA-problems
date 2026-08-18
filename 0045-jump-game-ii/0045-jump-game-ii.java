class Solution {
    // int recur(int[] nums, int idx){
        // if(idx==nums.length-1) {
        //     return 0;
        // }
        // int ans=Integer.MAX_VALUE;

        // for(int i=1; i<nums.length-idx && i<=nums[idx]; i++){
        //     int jumps=recur(nums, idx+i);
        //     if(jumps!=Integer.MAX_VALUE) ans=Math.min(jumps+1, ans);
        // }
        // return ans;
    // }
    // A zero at a non-final index returns Integer.MAX_VALUE because no jump is possible, while the final index returns 0 because no more jumps are needed.

    

    public int jump(int[] nums) {
        // // recursive/backtrack TC:- exponential
        //  return recur(nums, 0);
        
        // maximizing the farthest index we can reach after jumping from the index chosen by current jump
        // When all choices have the same immediate cost (one jump), choose the one that maximizes future reach.
        // TC:- O(n^2)
        // int i=0, jump=0;
        // while(i<nums.length-1){
        //     if(i+nums[i]>=nums.length-1) return jump+1;
        //     int index=i+1;
        //     for(int j=1; j<=nums[i]; j++){
        //         if(i+j+nums[i+j]>=index+nums[index]) index=i+j;
        //     }
        //     i=index;
        //     jump++;
        // }
        // return jump;

        // maintaining range TC:-O(n)
        int jumps=0, left=0, right=0;
        while(right<nums.length-1){
            int farthest=0;
            for(int i=left; i<=right; i++){
                farthest=Math.max(i+nums[i], farthest);
            }
            left=right+1;
            right=farthest;
            jumps++;
        }
        return jumps;
    }
}