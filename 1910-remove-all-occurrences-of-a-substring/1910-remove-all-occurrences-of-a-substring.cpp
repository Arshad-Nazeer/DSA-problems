class Solution {
public:
    string removeOccurrences(string s, string part) {
        // //O(n^2)
        // int pos=s.find(part);
        // while(pos!=string::npos){
        //     //s.replace(pos, part.size(), ""); //(starting index, no. of characters to remove, removal part)
        //     s.erase(pos, part.size());
        //     pos=s.find(part);
        // }
        // return s;

        string ans;

        for(char &c: s){
            ans.push_back(c);

            if(ans.size()>=part.size()){
                if(ans.substr(ans.size()-part.size())==part) ans.erase(ans.size()-part.size());
            }
        }
        return ans;
    }
};