class Solution {
    int count(int[] nums, int goal){
        if(goal<0) return 0;
        int left=0, right=0, sum=0, counter=0;
        while(right<nums.length){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left++];
            }
            counter+=right-left+1;
            right++;
        }
        return counter;
    }

    public int numSubarraysWithSum(int[] nums, int goal) {
        // sliding window
        return count(nums, goal)-count(nums, goal-1);

        // brute TC:-O(n^2), SC:-O(1)
        // int count=0;
        // for(int i=0; i<nums.length; i++){
        //     int sum=0;
        //     for(int j=i; j<nums.length; j++){
        //         sum+=nums[j];
        //         if(sum>goal) break;
        //         if(sum==goal) count++;
        //     }
        // }
        // return count;

        // prefix sum using hashmap TC:-O(n), SC:-O(n);
        // HashMap<Integer, Integer> prefix=new HashMap<>();
        // prefix.put(0, 1);
        // int currsum=0, counter=0;
        // for(int i=0; i<nums.length; i++){
        //     currsum+=nums[i];
        //     if(prefix.containsKey(currsum-goal)) counter+=prefix.get(currsum-goal);
        //     prefix.put(currsum, prefix.getOrDefault(currsum, 0)+1);
        // }
        // return counter;

        // prefix sum using array TC:-O(n), SC:-O(n);
        // int[] prefix=new int[nums.length+1];  // maximum sum possible is nums.length
        // prefix[0]=1;
        // int counter=0, sum=0;
        // for(int x: nums){
        //     sum+=x;
        //     if(sum-goal>=0) counter+=prefix[sum-goal];  // array cannot contain negative indices unlike hashmap's keys
        //     prefix[sum]++;
        // }
        // return counter;
    }
}