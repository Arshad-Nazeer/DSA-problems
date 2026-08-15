class Solution {
    // recursion
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

    // DP
    // boolean recur(String s, int track, int idx, Boolean[][] dp){
    //     if(track<0) return false;
    //     if(idx==s.length()) return track==0? true : false;

    //     if(dp[idx][track]!=null) return dp[idx][track];

    //     dp[idx][track] = switch(s.charAt(idx)){
    //         case '(' -> recur(s, track+1, idx+1, dp);
    //         case ')' -> recur(s, track-1, idx+1, dp);
    //         case '*' -> (recur(s, track, idx+1, dp) || recur(s, track+1, idx+1, dp) || recur(s, track-1, idx+1, dp));
    //         default -> false;
    //     };
    //     return dp[idx][track];
    // }


    public boolean checkValidString(String s) {
        // recursion
        // O(3ᵏ), where k is the number of * characters; worst case O(3ⁿ). 
        // Space(rescursion stack): O(n)
        // return recur(s, 0, 0);

        // DP memoization TC:-O(n^2), SC:- O(n^2)
        // dp[idx][track] = Can the substring from idx onward form a valid parenthesis string, given that we currently have track unmatched (?
        // Boolean[][] dp= new Boolean[s.length()][s.length()+1]; // default value is false
        // return recur(s, 0, 0, dp);

        // range greedy
        // lower = minimum possible number of unmatched (
        // higher = maximum possible number of unmatched (
        int lower=0, higher=0;
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i)=='('){
                lower++;
                higher++;
            }else if(s.charAt(i)==')'){
                lower--;
                higher--;
            }else{
                lower--;
                higher++;
            }
            if(lower<0) lower=0;
            if(higher<0) return false;  // If even the maximum is negative, then there is no possible interpretation that works.
        }
        return lower==0 ? true : false;
    }
}