class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
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

        // prefix count of odd numbers TC:- O(n) SC:-O(n)
        HashMap<Integer, Integer> mp=new HashMap<>();
        mp.put(0, 1);
        int odd=0, count=0;
        for(int i=0; i<nums.length; i++){
            if(nums[i]%2!=0) odd++;
            if(mp.containsKey(odd-k)) count+=mp.get(odd-k);
            mp.put(odd, mp.getOrDefault(odd, 0)+1);
        }
        return count;
    }
}