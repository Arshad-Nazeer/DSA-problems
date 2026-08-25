class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        // brute
        int count=0;
        for(int i=0; i<nums.length; i++){
            int sum=0;
            for(int j=i; j<nums.length; j++){
                sum+=nums[j];
                if(sum>goal) break;
                if(sum==goal) count++;
            }
        }
        return count;

        // prefix sum
        // HashMap<Integer, Integer> prefix=new HashMap<>();
        // prefix.put(0, 1);
        // int currsum=nums[0];
        // for(int i=0; i<nums.length; i++){
        //     currsum+=nums[i];
        //     prefix.put(currsum, prefix.getOrDefault(currsum, 0)+1);
        // }

        // int left=0, ones=0, count=0, firstidx=-1;
        // for(int right=0; right<nums.length; right++){
        //     if(nums[right]==1) {
        //         ones++;
        //         if(firstidx==-1) firstidx=right;
        //     } 
        //     if(ones==goal) {
        //         count+=firstidx-left+1;
        //     }
        //     if(ones>goal) {
        //         left=++firstidx;
        //         while(nums[firstidx]!=1) firstidx++;
        //         ones--;
        //     }
        // }
        // return count;
    }
}