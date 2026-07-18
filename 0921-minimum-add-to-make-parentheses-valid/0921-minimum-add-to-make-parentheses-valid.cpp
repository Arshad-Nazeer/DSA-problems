class Solution {
public:
    int minAddToMakeValid(string s) {
        // stack<char> st;
        // for(char &c: s){
        //     if(c=='(') st.push(c);
        //     else{
        //         if(!st.empty() && st.top()=='(') st.pop();
        //         else st.push(c);
        //     }
        // }
        // return st.size();

        //without stack
        int open=0, close=0;
        for(char &c: s){
            if(c=='(') open++;
            else{
                if(open>0) open--;
                else close++;
            }
        }
        return open+close;
    }
};