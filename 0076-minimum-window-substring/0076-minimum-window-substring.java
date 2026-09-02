class Solution {
    public String minWindow(String s, String t) {
        // brute force O(n^2*m)
        // HashMap<Character, Integer> need=new HashMap<>();
        // for(char c: t.toCharArray()) need.put(c, need.getOrDefault(c, 0)+1);

        // int n=s.length(), m=t.length(), start=0, minlen=Integer.MAX_VALUE;
        // for(int i=0; i<n-m+1; i++){
        //     HashMap<Character, Integer> freq=new HashMap<>();
        //     for(int j=i; j<n; j++){
        //         if(j-i+1>=minlen) break;
        //         freq.put(s.charAt(j), freq.getOrDefault(s.charAt(j), 0)+1);
        //         Boolean valid=true;
        //         for(char c: need.keySet()){
        //             if(freq.containsKey(c) && freq.get(c)>=need.get(c)) continue;
        //             else{
        //                 valid=false;
        //                 break;
        //             }
        //         }
        //         if(valid){
        //             if(j-i+1<minlen){
        //                 start=i;
        //                 minlen=j-i+1;
        //             }
        //             break;
        //         }
        //     }
        // } 
        // if(minlen==Integer.MAX_VALUE) return "";
        // return s.substring(start, start+minlen);

        // brute force O(n^2)
        // HashMap<Character, Integer> need=new HashMap<>();
        // for(char c: t.toCharArray()) need.put(c, need.getOrDefault(c, 0)+1);

        // int n=s.length(), m=t.length(), start=0, minlen=Integer.MAX_VALUE;
        // for(int i=0; i<n-m+1; i++){
        //     HashMap<Character, Integer> freq=new HashMap<>();
        //     int formed=0;
        //     for(int j=i; j<n; j++){
        //         if(j-i+1>=minlen) break;
        //         freq.put(s.charAt(j), freq.getOrDefault(s.charAt(j), 0)+1);
        //         if(freq.containsKey(s.charAt(j)) && freq.get(s.charAt(j))==need.get(s.charAt(j))) formed+=need.get(s.charAt(j));
        //         if(formed==m) {
        //             if(j-i+1<minlen){
        //                 start=i;
        //                 minlen=j-i+1;
        //             }
        //             break;
        //         }
        //     }
        // }
        // if(minlen==Integer.MAX_VALUE) return "";
        // else return s.substring(start, start+minlen);

        // sliding window O(n)
        int[] need=new int[256];
        int required=0;
        for(char c: t.toCharArray()) {
            if(need[c]==0) required++;
            need[c]++;
        }

        int left=0, formed=0, start=0, minlen=Integer.MAX_VALUE, n=s.length(), m=t.length();
        int freq[]=new int[256];
        for(int right=0; right<s.length(); right++){
            char curr=s.charAt(right);
            freq[curr]++;
            if(need[curr]>0 && freq[curr]==need[curr]) formed++;
            while(formed==required){
                if(right-left+1<minlen){
                    minlen=right-left+1;
                    start=left;
                }
                char front=s.charAt(left);
                freq[front]--;
                if(need[front]>0 && freq[front]<need[front]) {
                    formed--;
                }
                left++;
            }
        }
        return minlen==Integer.MAX_VALUE ? "" : s.substring(start, start+minlen);
    }
}