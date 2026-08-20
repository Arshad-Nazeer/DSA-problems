class Solution {
public:
    bool rotateString(string s, string goal) {
        //try all possible rotations by one
        // if(s.size()!=goal.size()) return false;
        // for(int i=0; i<s.size(); i++){
        //     string str=s.substr(i)+s.substr(0, i);
        //     if(str==goal) return true;
        // }
        // return false;    

        // //concatenation approach
        // if(s.size()!=goal.size()) return false;
        // return (s+s).find(goal)!=string::npos ? 1 : 0;

        return s.size() == goal.size() && (s + s).find(goal) != string::npos;
    }
};