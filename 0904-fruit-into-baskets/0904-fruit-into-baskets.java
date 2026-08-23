class Solution {
    public int totalFruit(int[] fruits) {
        // brute force TC:-O(n^2) SC:-O(1)
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

        // sliding winodw+last occurence stored in hashmap, TC:- O(n), SC:- O(1)
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

        // sliding window+tracking frequency in hashmap, TC:- O(n), SC:- O(1)
        // int left=0, ans=0;
        // HashMap<Integer, Integer> count = new HashMap<>();
        // for(int right=0; right<fruits.length; right++){
        //     count.put(fruits[right], count.getOrDefault(fruits[right], 0)+1);
        //     while(count.size()>2){
        //         count.put(fruits[left], count.get(fruits[left])-1);
        //         if(count.get(fruits[left])==0) count.remove(fruits[left]);
        //         left++;
        //     }
        //     ans=Math.max(right-left+1, ans);
        // }
        // return ans;

        // sliding window+ optimal TC:-O(n), SC:-O(1);
        // int left=0, ans=0, fruit1=-1, fruit2=-1, last1=-1, last2=-1;
        // for(int right=0; right<fruits.length; right++){
        //     if(fruit1==-1 || fruits[right]==fruit1){
        //         fruit1=fruits[right];
        //         last1=right;
        //     }else if(fruit2==-1 || fruits[right]==fruit2){
        //         fruit2=fruits[right];
        //         last2=right;
        //     }else{
        //         if(last1<last2){
        //             left=last1+1;
        //             fruit1=fruits[right];
        //             last1=right;
        //         }else{
        //             left=last2+1;
        //             fruit2=fruits[right];
        //             last2=right;
        //         }
        //     }
        //     ans=Math.max(ans, right-left+1);
        // }
        // return ans;
    }
}
