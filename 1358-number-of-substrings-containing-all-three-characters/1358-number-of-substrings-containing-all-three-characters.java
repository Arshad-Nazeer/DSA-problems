class Solution {
    public int numberOfSubstrings(String s) {
        // brute force TC:-O(n^2)
        // int count=0;
        // for(int i=0; i<s.length(); i++){
        //     HashMap<Character, Integer> freq=new HashMap<>();
        //     freq.put('a', 0);
        //     freq.put('b', 0);
        //     freq.put('c', 0);
        //     for(int j=i; j<s.length(); j++){
        //         freq.put(s.charAt(j), freq.get(s.charAt(j))+1);
        //         if(freq.get('a')>0 && freq.get('b')>0 && freq.get('c')>0) count++;
        //     }
        // }
        // return count;

        // sliding window TC:-O(n)
        // int left=0, n=s.length(), count=0;
        // int[] freq=new int[3];
        // for(int right=0; right<n; right++){
        //     freq[s.charAt(right)-'a']++;
        //     while(freq[0]>0 && freq[1]>0 && freq[2]>0){
        //         count+=n-right;
        //         freq[s.charAt(left)-'a']--;
        //         left++;
        //     }
        // }
        // return count;

        // last occurence approach TC:-O(n)
        int count=0;
        int[] last=new int[3];
        last[0]=-1;
        last[1]=-1;
        last[2]=-1;
        for(int i=0; i<s.length(); i++){
            last[s.charAt(i)-'a']=i;
            int minidx=Math.min(last[0], Math.min(last[1], last[2]));
            if(minidx!=-1) count+=minidx+1;
        }
        return count;
    }
}