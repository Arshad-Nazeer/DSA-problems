class Solution {
public:
    string longestPalindrome(string s) {
        // // brute O(n^3) ->
        // string ans="";
        // for(int i=0; i<s.size(); i++){
        //     for(int j=i; j<s.size(); j++){
        //         int left=i, right=j;
        //         if(j-i+1<=ans.size()) continue;
        //         while(left<right){
        //             if(s[left]!=s[right]) break;
        //             left++;
        //             right--;
        //         }
        //         if(left>=right) ans=s.substr(i, j-i+1);
        //     }
        // }
        // return ans;

        // expanding around center TC:-O(n^2)
        string ans="";
        for(int i=0; i<s.size(); i++){
            // expanding for odd palindromes
            int left=i, right=i;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1>ans.size()) ans=s.substr(left+1, right-left-1);

            //expanding for even palindromes
            left=i, right=i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-1>ans.size()) ans=s.substr(left+1, right-left-1);
        }
        return ans;
    }
};