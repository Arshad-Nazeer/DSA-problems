class Solution {
    // boolean recur(String s, int track, int idx){
    //     if(track<0) return false;
    //     if(idx==s.length()){
    //         return track==0 ? true : false;
    //     }

    //     if(s.charAt(idx)=='(') return recur(s, track+1, idx+1);
    //     else if(s.charAt(idx)==')') return recur(s, track-1, idx+1);
    //     else return recur(s, track, idx+1) || recur(s, track+1, idx+1) || recur(s, track-1, idx+1); 
    //     // ignore asterisk or replace by '(' or replcae by ')'
    // }

    boolean recur(String s, int track, int idx, Boolean[][] dp){
        if(track<0) return false;
        if(idx==s.length()) return track==0? true : false;

        if(dp[idx][track]!=null) return dp[idx][track];

        dp[idx][track] = switch(s.charAt(idx)){
            case '(' -> recur(s, track+1, idx+1, dp);
            case ')' -> recur(s, track-1, idx+1, dp);
            case '*' -> (recur(s, track, idx+1, dp) || recur(s, track+1, idx+1, dp) || recur(s, track-1, idx+1, dp));
            default -> false;
        };
        return dp[idx][track];
    }


    public boolean checkValidString(String s) {
        // recursion
        // O(3ᵏ), where k is the number of * characters; worst case O(3ⁿ). 
        // Space(rescursion stack): O(n)
        // return recur(s, 0, 0);

        // DP memoization TC:-O(n^2), SC:- O(n^2)
        Boolean[][] dp= new Boolean[s.length()][s.length()+1]; // default value is false
        return recur(s, 0, 0, dp);
    }
}