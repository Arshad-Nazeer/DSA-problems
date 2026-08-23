class Solution {
    public int totalFruit(int[] fruits) {
        // brute force TC:-O(n^2) SC:-O(n)
        // int ans=0, n=fruits.length;
        // for(int i=0; i<n; i++){
        //     HashSet<Integer> types = new HashSet<>();
        //     int j=i;
        //     while(j<n){
        //         types.add(fruits[j]);
        //         if(types.size()>2) break;
        //         j++;
        //     }
        //     ans=Math.max(ans, j-i);
        // }   
        // return ans;

        // int ans=0, n=fruits.length;
        // for(int i=0; i<n; i++){
        //     HashMap<Integer, Integer> mp = new HashMap<>();
        //     int j=i;
        //     while(j<n){
        //         mp.put(fruits[j], 0);
        //         if(mp.size()>2) break;
        //         j++;
        //     }
        //     ans=Math.max(ans, j-i);
        // }
        // return ans;

        // sliding winodw+last occurence stored in hashmap
        int left=0, right=0, ans=0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        while(right<fruits.length){
            mp.put(fruits[right], right);
            if(mp.size()>2){
                int lastidx=Integer.MAX_VALUE;
                for(int value: mp.values()) lastidx=Math.min(lastidx, value);
                mp.remove(fruits[lastidx]);
                left=lastidx+1;
            }
            ans=Math.max(ans, right-left+1);
            right++;
        }
        return ans;
    }
}