class Solution {
public:
    string removeOccurrences(string s, string part) {
        // //O(k(n*m+n)) 
        // int pos=s.find(part);
        // while(pos!=string::npos){
        //     //s.replace(pos, part.size(), ""); //(starting index, no. of characters to remove, removal part)
        //     s.erase(pos, part.size());
        //     pos=s.find(part);
        // }
        // return s;

        // // TC:- O(n*m) however substring creates new string everytime
        // string ans;

        // for(char &c: s){
        //     ans.push_back(c);

        //     if(ans.size()>=part.size()){
        //         if(ans.substr(ans.size()-part.size())==part) ans.erase(ans.size()-part.size());
        //     }
        // }
        // return ans;

        // TC:- O(n*m)
        string ans;
        for(char &c: s){
            ans.push_back(c);
            if(ans.size()>=part.size()){
                bool match=true;
                for(int i=0; i<part.size(); i++){
                    if(ans[ans.size()-part.size()+i]!=part[i]) {
                        match=false;
                        break;
                    }
                }
                if(match) ans.erase(ans.size()-part.size());
            }
        }
        return ans;
    }
};