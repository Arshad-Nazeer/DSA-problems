class Solution {
public:
    string reverseWords(string s) {
        // TC:- O(n)
        string ans="";
        reverse(s.begin(), s.end());
        for(int i=0; i<s.size(); i++){
            string word="";
            while(i<s.size() && s[i]!=' '){
                word+=s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.length()>0) ans+=word+" ";
        }
        if(ans.size()) ans.pop_back();
        return ans;

        // //laand Approach TC:-O(n) and SC:-O(n);
        // deque<string> dq;  //although a vector would have been better by a reversing the entire vector by reverse() function after pushing back each string
        // stringstream ss(s);
        // while(getline(ss, s, ' ')){
        //     if(s!="") dq.push_front(s);
        // }
        // s="";
        // for(string& str: dq){
        //     s+=str+" ";
        // }
        // s.pop_back();
        // return s;
    }
};