class Solution {
public:
    bool isPalindrome(string s) {
        // //transforming string approach
        // string str;
        // for(char& c: s){
        //     if(isalpha(c) ||  isdigit(c)) str.push_back(tolower(c));
        // }
        // s=str;
        // reverse(s.begin(), s.end());
        // return s==str;

        // //two pointer
        int left=0, right=s.size()-1;
        while(left<right){
            if(!isalnum(s[left])) left++;
            else if(!isalnum(s[right])) right--;
            // else{
            //     if(tolower(s[left++])!=tolower(s[right--])) return 0;
            // }
            else if(tolower(s[left])==tolower(s[right])){
                left++;
                right--;
            }
            else return 0;
        }
        return 1;
    }
};