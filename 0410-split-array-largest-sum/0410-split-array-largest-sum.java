class Solution {
    boolean allocationPossible(int[] nums, int k, int mid){
        int counter=1, sum=0;
        for(int x: nums){
            if(sum+x<=mid) sum+=x;
            else{
                sum=x;
                counter++;
                if(counter>k) return false;
            }
        }
        return true;
    }

    public int splitArray(int[] nums, int k) {
        // Binary Search O(n*log(sum(nums)-min(nums)))
        int low=Integer.MIN_VALUE, high=0, ans=-1;
        for(int x: nums){
            low=Math.max(low, x);  // when k=nums.length
            high+=x;          // when k=1
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(allocationPossible(nums, k, mid)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
}