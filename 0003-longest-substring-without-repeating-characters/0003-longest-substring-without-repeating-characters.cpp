class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //optimized approach
        vector<int> last(256, -1);
        int left=0, right=0, len=0;
        
        while(right<s.size()){
            if(last[s[right]]>=left) left=last[s[right]]+1;
            last[s[right]]=right;
            len=max(len, right-left+1);
            right++;
        }
        return len;

        //HashSet Approach
        // unordered_set<char> st;
        // int right=0, left=0,  len=0;
        // while(right<s.size()){
        //     if(st.find(s[right])==st.end()){
        //         st.insert(s[right]);
        //         len=max(len, right-left+1);
        //         right++;
        //     }else{
        //         st.erase(s[left]);
        //         left++;
        //     }
        // }
        // return len;

        //HashMap Approach
        // if(s.size()==0) return 0;
        // unordered_map<char, int> mp;
        // int left=0, right=0, len=0;
        // while(right<s.size()){
        //     mp[s[right]]++;
        //     while(mp[s[right]]>1){
        //         mp[s[left]]--;
        //         left++;
        //     }
        //     len=max(len, right-left+1);
        //     right++;
        // }
        // return len;

        // //Laand Approach
        // int maxLength = 0;
        // int n = s.length();
        // for (int i = 0; i < n; i++) {
        //     unordered_set<char> charSet;
        //     for (int j = i; j < n; j++) {
        //         if (charSet.find(s[j]) != charSet.end()) break;
        //         charSet.insert(s[j]);
        //         maxLength = max(maxLength, j - i + 1);
        //     }
        // }
        // return maxLength;
    }
};