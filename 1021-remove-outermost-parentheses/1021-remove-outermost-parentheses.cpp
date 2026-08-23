class Solution {
public:
    string removeOuterParentheses(string s) {
        //stack
        // stack<char> st;
        // string result="";
        // for(int i=0; i<s.size(); i++){
        //     if(s[i]=='('){
        //         if(!st.empty()) result+='(';
        //         st.push('(');
        //     }else{
        //         st.pop();
        //         if(!st.empty()) result+=')';
        //     }
        // }
        // return result;

        //optimal
        int depth=0;
        string result="";
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                if(depth!=0) result+='(';
                depth++;
            }else{
                depth--;
                if(depth!=0) result+=')';
            }
        }
        return result;
    }
};