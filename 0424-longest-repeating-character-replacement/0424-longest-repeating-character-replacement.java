class Solution {
    public int characterReplacement(String s, int k) {
        // brute force TC:-O(N^2) SC:-O(N)
        // int maxlen=Integer.MIN_VALUE;
        // for(int i=0; i<s.length(); i++){
        //     HashMap<Character, Integer> freq=new HashMap<>();
        //     int changes=0;
        //     int maxfreq=Integer.MIN_VALUE;
        //     for(int j=i; j<s.length(); j++){
        //         freq.put(s.charAt(j), freq.getOrDefault(s.charAt(j), 0)+1);
        //         maxfreq=Math.max(maxfreq, freq.get(s.charAt(j)));
        //         changes=(j-i+1)-maxfreq;
        //         if(changes<=k) maxlen=Math.max(maxlen, j-i+1);
        //         else break;
        //     }
        // }
        // return maxlen;

        //sliding window TC:-O(26*n), SC:-O(n)
        int[] freq=new int[26];
        int left=0, maxfreq=0, ans=0;
        for(int right=0; right<s.length(); right++){
            freq[s.charAt(right)-'A']++;
            maxfreq=Math.max(maxfreq, freq[s.charAt(right)-'A']);
            while((right-left+1)-maxfreq>k){
                freq[s.charAt(left)-'A']--;
                maxfreq=0;
                for(int x: freq) maxfreq=Math.max(maxfreq, x);
                left++;
            }
            ans=Math.max(right-left+1, ans);
        }
        return ans;
    }
}