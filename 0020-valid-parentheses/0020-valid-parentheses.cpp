class Solution {
public:
    bool isValid(string s) {
        stack<int> bracket;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') bracket.push(s[i]);
            else{
                if(bracket.empty()) return false;    //"()}"
                if((bracket.top()=='(' && s[i]==')') || (bracket.top()=='{' && s[i]=='}') || (bracket.top()=='[' && s[i]==']')) bracket.pop();    
                else return false;    //"{()]"
            }
        }
        return bracket.empty();      //"{()"
    }
};