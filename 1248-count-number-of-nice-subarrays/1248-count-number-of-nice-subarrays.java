class Solution {
    int atmost(int[] nums, int k){
        int left=0, odd=0, count=0;
        for(int right=0; right<nums.length; right++){
            if(nums[right]%2!=0) odd++;
            while(odd>k) {
                if(nums[left]%2!=0) odd--;
                left++;
            }
            count+=right-left+1;
        }
        return count;
    }

    public int numberOfSubarrays(int[] nums, int k) {
        // sliding window to count at most k odds subarrays
        return atmost(nums, k)-atmost(nums, k-1);

        // brute force O(n^2)
        // int count=0, n=nums.length;
        // for(int i=0; i<n; i++){
        //     int odd=0;
        //     for(int j=i; j<n; j++){
        //         if(nums[j]%2!=0) odd++;
        //         if(odd==k) count++;
        //         if(odd>k) break;
        //     }
        // }
        // return count;

        // // prefix count of odd numbers TC:- O(n) SC:-O(n)
        // HashMap<Integer, Integer> mp=new HashMap<>();
        // mp.put(0, 1);
        // int odd=0, count=0;
        // for(int i=0; i<nums.length; i++){
        //     if(nums[i]%2!=0) odd++;
        //     if(mp.containsKey(odd-k)) count+=mp.get(odd-k);
        //     mp.put(odd, mp.getOrDefault(odd, 0)+1);
        // }
        // return count;

        // int[] prefix=new int[nums.length+1];
        // prefix[0]=1;
        // int count=0, odd=0;
        // for(int i=0; i<nums.length; i++){
        //     if(nums[i]%2!=0) odd++;
        //     if(odd-k>=0) count+=prefix[odd-k];
        //     prefix[odd]++;
        // }
        // return count;
    }
}