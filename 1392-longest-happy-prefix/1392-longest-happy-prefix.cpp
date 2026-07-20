class Solution {
public:
    string longestPrefix(string s) {
        // LPS array TC:- O(4*n), SC:- O(n);
        int maxlen=0;
        vector<int> lps(s.size(), 0);
        int len=0, i=1;
        while(i<s.size()){
            if(s[len]==s[i]){
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
        return s.substr(0, lps.back());

        // // brute force tC:- 3*((n-1) + (n-2) + (n-3) + ... + 2 + 1) = 3 × (n-1)n/2 = (n^2)
        // int n=s.size();
        // for(int i=n-1; i>=1; i--){
        //     if(s.substr(0, i)==s.substr(n-i)) return s.substr(0, i);
        // }
        // return "";
    }
};