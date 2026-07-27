class Solution {
public:
    string longestPalindrome(string s) {
        // brute O(n^3) ->
        string ans="";
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                int left=i, right=j;
                if(j-i+1<=ans.size()) continue;
                while(left<right){
                    if(s[left]!=s[right]) break;
                    left++;
                    right--;
                }
                if(left>=right) ans=s.substr(i, j-i+1);
            }
        }
        return ans;
    }
};