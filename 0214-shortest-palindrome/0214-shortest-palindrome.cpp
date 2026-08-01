class Solution {
public:
    // bool palindrome(int left, int right, const string& s){
    //     while(left<right){
    //         if(s[left++]!=s[right--]) return false;
    //     }
    //     return true;
    // }

    string shortestPalindrome(string s) {
        // // brute TC:- O(n^2+n) TLE
        // for(int i=s.size()-1; i>=0; i--){
        //     if(palindrome(0, i, s)){
        //         string suffix=s.substr(i+1);
        //         return string(suffix.rbegin(), suffix.rend())+s;
        //     }
        // }
        // return "";

        // Optimal using LPS array TC:-O(n) SC:- O(n)
        string rev=string(s.rbegin(), s.rend());
        string temp=s+"#"+rev;

        vector<int> lps(temp.size());

        int len=0, i=1;
        while(i<temp.size()){
            if(temp[len]==temp[i]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len>0) len=lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        string suffix=s.substr(lps.back());
        reverse(suffix.begin(), suffix.end());
        return suffix+s;
    }
};